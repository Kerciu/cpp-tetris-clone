#include "game.h"

Game::Game() : grid(Grid()), blocks(generate_blocks()), current_block(nullptr), next_block(nullptr)
{
    this->current_block = get_random_block();
    this->next_block = get_random_block();
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

void Game::move_block_left()
{
    current_block->move_block(-1, 0);
    if (is_block_outside()) current_block->move_block(1, 0);
}

void Game::move_block_right()
{
    current_block->move_block(1, 0);
    if (is_block_outside()) current_block->move_block(-1, 0);
}

void Game::move_block_down()
{
    current_block->move_block(0, 1);
    if (is_block_outside()) current_block->move_block(0, -1);
}

void Game::move_block_down(bool debug) {
    auto original_position = current_block->get_occupied_cell_positions();
    current_block->move_block(0, 1);
    if (is_block_outside()) {
        current_block->move_block(0, -1);
        std::cout << "Block outside after move down. Reverting move." << std::endl;
    } else {
        auto new_position = current_block->get_occupied_cell_positions();
        std::cout << "Moved block down. Original position: ";
        for (const auto& pos : original_position) {
            std::cout << "(" << pos.get_x() << ", " << pos.get_y() << ") ";
        }
        std::cout << ". New position: ";
        for (const auto& pos : new_position) {
            std::cout << "(" << pos.get_x() << ", " << pos.get_y() << ") ";
        }
        std::cout << std::endl;
    }
}

void Game::rotate_block()
{
    current_block->rotate();
    if (is_block_outside()) current_block->undo_rotation();
}

void Game::handle_input()
{   
    auto now = std::chrono::steady_clock::now();
    sf::Keyboard::Key key_pressed = get_key_pressed();
    
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
        if (!grid.validate_bounds(v.get_x(), v.get_y()))
        {
            return true;
        }
    }

    return false;
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

void Game::display(sf::RenderWindow* window)
{
    grid.display(window);
    if (current_block) current_block->draw_block(window);
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