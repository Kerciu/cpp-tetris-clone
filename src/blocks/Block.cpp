#include "Block.h"
#include <iostream>

Block::Block() : cell_size(30), rotation(0), block_id(0), row_offset(0), col_offset(0)
{
    colors = get_cell_colors();
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

Block::color_vector Block::get_color_vector()
{
    return colors;
}

void Block::set_block_id(int block_id)
{
    this->block_id = block_id;
}

std::map<Block::rotation_state, Block::position_vector> *Block::get_cells_ptr()
{
    return &cells;
}

void Block::initialize_position_states(BlockType type) {
    std::vector<position_vector> position_vec = create_position_vec();

    for (int i = 0; i < 4; ++i) {
        cells[i] = position_vec[i];
    }

    spawn_in_the_middle(type);
        
}

void Block::draw_block(sf::RenderWindow* window) {
    position_vector tiles = get_occupied_cell_positions();
    int cell_size = this->get_cell_size();

    for (Coords& coord : tiles) {
        int x_coord = coord.get_x() * cell_size + OFFSET;
        int y_coord = coord.get_y() * cell_size + OFFSET;

        sf::Color top_color = get_cell_colors()[this->get_block_id()];
        sf::Color bottom_color = get_appropriate_gradient_color(top_color);


        sf::VertexArray gradient = GradientCreator::create_gradient(std::make_pair(top_color, bottom_color), std::make_pair(cell_size - OFFSET, cell_size - OFFSET));

        for (size_t i = 0; i < gradient.getVertexCount(); ++i) {
            gradient[i].position += sf::Vector2f(x_coord, y_coord);
        }

 
        window->draw(gradient);
    }
}

void Block::rotate()
{
    rotation = (++rotation) % (int)cells.size();
}

void Block::undo_rotation()
{
    rotation = (rotation - 1 + cells.size()) % cells.size();
}

void Block::move_block(offset row, offset col)
{
    this->row_offset += row;
    this->col_offset += col;
}

Block::position_vector Block::get_occupied_cell_positions() {
    position_vector tiles = cells[rotation];
    position_vector moved_tiles;

    for (Coords& coord : tiles) {
        Coords new_coord = Coords(coord.get_row() + row_offset, coord.get_col() + col_offset);
        moved_tiles.push_back(new_coord);
    }

    return moved_tiles;
}

void Block::spawn_in_the_middle(BlockType type) {
    switch (type) {
        case BlockType::O_BLOCK:
            this->move_block(0, 4);
            break;
        case BlockType::I_BLOCK:
            this->move_block(-1, 3);
            break;
        default:
            this->move_block(0, 3);
            break;
    }
}