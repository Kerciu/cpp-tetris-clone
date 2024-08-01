#include "process.h"

Process::Process() : grid(Grid()), blocks(generate_blocks()), current_block(nullptr), next_block(nullptr)
{
    this->current_block = get_random_block();
    this->next_block = get_random_block();
}

Grid Process::get_grid()
{
    return grid;
}

Process::block_vector Process::get_blocks()
{
    // deep copy of blocks vector
    block_vector dummy;
    for (const auto& block : blocks) {
        dummy.push_back(block->clone());
    }
    return dummy;
}

void Process::set_grid(Grid new_grid)
{
    this->grid = new_grid;
}

void Process::set_blocks(block_vector new_blocks)
{
    this->blocks = std::move(new_blocks);
}

void Process::move_block_left()
{
    current_block->move_block(-1, 0);
}

void Process::move_block_right()
{
    current_block->move_block(1, 0);
}

void Process::move_block_down()
{
    current_block->move_block(0, 1);
}

void Process::handle_input()
{
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
        default:
            break;
        }
}

sf::Keyboard::Key Process::get_key_pressed() {
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

    return sf::Keyboard::Unknown;
}

void Process::display(sf::RenderWindow* window)
{
    grid.display(window);
    if (current_block) current_block->draw_block(window);
}

std::unique_ptr<Block> Process::get_random_block() 
{
    fill_empty_vector();

    int idx = get_random_index();
    std::unique_ptr<Block> block = std::move(this->blocks[idx]);
    blocks.erase(blocks.begin() + idx);
    return block;
}

void Process::fill_empty_vector() {
    if (blocks.empty()) {
        this->blocks = generate_blocks();
    }
}

int Process::get_random_index() const
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dist(0, blocks.size() - 1);

    return dist(mt);
}

Process::block_vector Process::generate_blocks() 
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