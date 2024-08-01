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

Process::block_vector generate_blocks() {
    return { IBlock(), JBlock(), 
             LBlock(), OBlock(),
             SBlock(), TBlock(),
             ZBlock()};
}