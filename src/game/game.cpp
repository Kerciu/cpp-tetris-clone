#include "game.h"

Game::Game() : grid(Grid()), blocks(generate_blocks()), current_block(nullptr), next_block(nullptr), game_over(false)
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

void Game::set_grid(Grid new_grid)
{
    this->grid = new_grid;
}

void Game::set_blocks(block_vector new_blocks)
{
    this->blocks = std::move(new_blocks);
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
    }

    next_block = get_random_block();
    grid.clear_full_rows();
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