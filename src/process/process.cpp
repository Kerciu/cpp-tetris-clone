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
    return blocks;
}

void Process::set_grid(Grid new_grid)
{
    this->grid = new_grid;
}

void Process::set_blocks(block_vector new_blocks)
{
    this->blocks = new_blocks;
}

std::unique_ptr<Block> Process::get_random_block() 
{
    if (blocks.empty()) {
        this->blocks = generate_blocks();
    }

    int idx = get_random_index();
    std::unique_ptr<Block> block = std::make_unique<Block>(this->blocks[idx]);
    blocks.erase(blocks.begin() + idx);
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
    return { IBlock(), JBlock(), 
             LBlock(), OBlock(),
             SBlock(), TBlock(),
             ZBlock()};
}