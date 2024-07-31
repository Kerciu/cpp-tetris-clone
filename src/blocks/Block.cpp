#include "Block.h"

Block::Block()
{
    cell_size = 30;
    rotation = 0;
    colors = get_cell_colors();
}

void Block::draw_block()
{

}

int Block::get_block_id()
{
    return block_id;
}

int Block::get_cell_size()
{
    return cell_size;
}

Block::rotation_state Block::get_rotation_state()
{
    return rotation;
}

void Block::set_block_id(int block_id)
{
    this->block_id = block_id;
}

std::map<Block::rotation_state, Block::position_vector> *Block::get_cells_ptr()
{
    return &cells;
}
