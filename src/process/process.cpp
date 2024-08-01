#include "process.h"

Process::Process()
{
    this->grid = Grid();
    this->blocks = generate_blocks();
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

void Process::display(sf::RenderWindow* window)
{
    grid.display(window);
    current_block->draw_block(window);
}

std::unique_ptr<Block> Process::get_random_block() 
{
    if (blocks.empty()) {
        this->blocks = generate_blocks();
    }

    int idx = get_random_index();
    std::unique_ptr<Block> block = std::move(this->blocks[idx]);
    blocks.erase(blocks.begin() + idx);
    return block;
}

int Process::get_random_index()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dist(0, blocks.size() - 1);

    return dist(mt);
}

Process::block_vector generate_blocks() 
{
    return {
        std::make_unique<IBlock>(),
        std::make_unique<JBlock>(), 
        std::make_unique<LBlock>(), 
        std::make_unique<OBlock>(),
        std::make_unique<SBlock>(), 
        std::make_unique<TBlock>(),
        std::make_unique<ZBlock>()
    };
}