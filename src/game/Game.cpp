#include "Game.h"

Game::Game() : audio_player("../assets/sound/"), 
               grid(Grid()), blocks(generate_blocks()), game_over(false), score(Score()),
               current_block(nullptr), next_block(nullptr)
{
    initialize_blocks();
}

Grid Game::get_grid()
{
    return grid;
}

Game::block_vector Game::get_blocks()
{
    // deep copy of blocks vector
    block_vector dummy;
    for (const auto& block : blocks) {
        dummy.push_back(block->clone());
    }
    return dummy;
}

Score Game::get_score()
{
    return score;
}

void Game::set_grid(Grid new_grid)
{
    this->grid = new_grid;
}

void Game::set_blocks(block_vector new_blocks)
{
    this->blocks = std::move(new_blocks);
}

void Game::set_score(const Score &new_score)
{
    this->score = new_score;
}

void Game::display_block_coords()
{
    Block::position_vector vec = current_block->get_occupied_cell_positions();
    for (auto& pos : vec) {
        std::cout << "Block pos: x(" << pos.get_x() << ") y(" << pos.get_y() << ")\n";
    }
}

void Game::move_block_left()
{
    if (!game_over) {
        current_block->move_block(0, -1);
    
        if (is_block_outside() || !block_fits()) current_block->move_block(0, 1);
    }
}

void Game::move_block_right()
{
    if (!game_over) {
        current_block->move_block(0, 1);
    
        if (is_block_outside() || !block_fits()) current_block->move_block(0, -1);
    }
}

void Game::move_block_down()
{
    if (!game_over) {
        current_block->move_block(1, 0);
    
        if (is_block_outside() || !block_fits()) {
            current_block->move_block(-1, 0);
            lock_block();
        }
    }
}

void Game::rotate_block()
{
    if (!game_over) {
        current_block->rotate();
        if (is_block_outside() || !block_fits()) current_block->undo_rotation();
        else play_rotation_sound();
    }
}

void Game::play_rotation_sound() {
    if (!audio_player.load_sound("rotation-sound.mp3")) {
        std::cerr << "Failed to load rotation sound" << std::endl;
    } else {
        audio_player.set_sound_volume(10);
        audio_player.play_specific_sound();
    }
}

void Game::lock_block()
{
    Block::position_vector pos = current_block->get_occupied_cell_positions();

    for (auto& coord : pos) {
        (*grid.get_grid_distribution())[coord.get_row()][coord.get_col()] = current_block->get_block_id();
    }

    current_block = std::move(next_block);

    if (!block_fits()) 
    {
        game_over = true;
        play_game_over_sound();
    }

    score.update_score_on_lock(10);
    next_block = get_random_block();

    int cleared_rows = grid.clear_full_rows();
    if (cleared_rows > 0) {
        play_clear_row_sound();
        score.update_score_rows_cleared(cleared_rows);
    }
}

void Game::play_clear_row_sound() {
    if (!audio_player.load_sound("clear-sound.mp3")) {
        std::cerr << "Failed to load rotation sound" << std::endl;
    } else {
        audio_player.set_sound_volume(10);
        audio_player.play_specific_sound();
    }
}

void Game::play_game_over_sound()
{
    if (!audio_player.load_sound("game-over.mp3")) {
        std::cerr << "Failed to load game over sound" << std::endl;
    } 

    else {
        audio_player.set_sound_volume(15);
        audio_player.play_specific_sound();
    }
}

void Game::handle_input()
{   
    auto now = std::chrono::steady_clock::now();
    sf::Keyboard::Key key_pressed = get_key_pressed();

    if (game_over) {
        if (key_pressed != sf::Keyboard::Unknown && can_execute(key_pressed, now)) {
            game_over = false;
            this->reset();
        }
        return;
    }
    
    if (key_pressed != sf::Keyboard::Unknown && can_execute(key_pressed, now)) {
        switch(get_key_pressed()) {
            case sf::Keyboard::Left:
                move_block_left();
                break;
            case sf::Keyboard::Right:
                move_block_right();
                break;
            case sf::Keyboard::Down:
                move_block_down();
                break;
            case sf::Keyboard::Up:
                rotate_block();
                break;
            default:
                break;
        }
    }
    last_key_press_time[key_pressed] = now;
}

bool Game::is_block_outside()
{
    Block::position_vector tiles = current_block->get_occupied_cell_positions();

    for (Coords& v : tiles) {
        if (!grid.validate_bounds(v.get_row(), v.get_col()))
        {
            return true;
        }
    }

    return false;
}

bool Game::block_fits()
{
    Block::position_vector pos = current_block->get_occupied_cell_positions();

    for (Coords& coord : pos)
    {
        if (!grid.is_cell_empty(coord.get_row(), coord.get_col()))
        {
            return false;
        }
    }

    return true;
}

sf::Keyboard::Key Game::get_key_pressed()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        return sf::Keyboard::Left;
    } 
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        return sf::Keyboard::Right;
    } 
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        return sf::Keyboard::Down;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        return sf::Keyboard::Up;
    }

    return sf::Keyboard::Unknown;
}

bool Game::can_execute(sf::Keyboard::Key key, std::chrono::steady_clock::time_point now) {
    auto it = last_key_press_time.find(key);
    if (it != last_key_press_time.end()) {
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - it->second);
        return elapsed >= debounce_time;
    }
    return true;
}

void Game::reset()
{
    grid.initialize_grid();
    blocks = generate_blocks();
    initialize_blocks();
    score.set_score(0);
}

void Game::initialize_blocks()
{
    this->current_block = get_random_block();
    this->next_block = get_random_block();
}

void Game::display(sf::RenderWindow* window)
{
    grid.display(window);
    if (current_block) current_block->draw_block(window);
    if (next_block) display_next_block(window);
}

void Game::display_next_block(sf::RenderWindow* window)
{
    switch(get_block_type(next_block->get_block_id()))
    {
        case Block::BlockType::I_BLOCK:
            next_block->draw_block(window, 298, 117);
            break;
        case Block::BlockType::O_BLOCK:
            next_block->draw_block(window, 298, 107);
            break;
        default:
            next_block->draw_block(window, 313, 97);
            break;
    }
}

Block::BlockType Game::get_block_type(int block_id)
{
    Block::BlockType type;

    if (block_id == 3)
        type = Block::BlockType::I_BLOCK;
    else if (block_id == 4)
        type = Block::BlockType::O_BLOCK;
    else
        type = Block::BlockType::OTHER_BLOCK;

    return type;
}

bool Game::is_game_over()
{
    return game_over;
}

std::unique_ptr<Block> Game::get_random_block() 
{
    fill_empty_vector();

    int idx = get_random_index();
    std::unique_ptr<Block> block = std::move(this->blocks[idx]);
    blocks.erase(blocks.begin() + idx);
    return block;
}

void Game::fill_empty_vector() {
    if (blocks.empty()) {
        this->blocks = generate_blocks();
    }
}

int Game::get_random_index() const
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dist(0, blocks.size() - 1);

    return dist(mt);
}

Game::block_vector Game::generate_blocks() 
{
    block_vector vec;

    vec.push_back(std::make_unique<IBlock>());
    vec.push_back(std::make_unique<JBlock>());
    vec.push_back(std::make_unique<LBlock>());
    vec.push_back(std::make_unique<OBlock>());
    vec.push_back(std::make_unique<SBlock>());
    vec.push_back(std::make_unique<TBlock>());
    vec.push_back(std::make_unique<ZBlock>());
    
    return vec;
}