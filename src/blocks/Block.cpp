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
        (*this->get_cells_ptr())[i] = position_vec[i];
    }
    spawn_in_the_middle(type);
        
}

void Block::draw_block(sf::RenderWindow* window) {
    position_vector tiles = get_occupied_cell_positions();
    int cell_size = this->get_cell_size();

    for (Coords& coord : tiles) {
        int x_coord = coord.get_x() * cell_size + OFFSET;
        int y_coord = coord.get_y() * cell_size + OFFSET;

        std::cout << "Drawing rectangle at (" << x_coord << ", " << y_coord << ")" << std::endl;

        int width, height;
        width = height = cell_size - OFFSET;
        sf::Color color = get_cell_colors()[this->get_block_id()];

        sf::RectangleShape rectangle(sf::Vector2f(width, height));

        rectangle.setFillColor(color);
        rectangle.setPosition(sf::Vector2f(x_coord, y_coord));
        window->draw(rectangle);
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

void Block::move_block(offset rows, offset cols)
{
    /*debug*/
    std::cout << "Moving block by rows: " << rows << ", cols: " << cols << std::endl;
    this->row_offset += rows;
    this->col_offset += cols;

    /*debug*/
    auto new_positions = get_occupied_cell_positions();
    std::cout << "New positions: ";
    for (const auto& pos : new_positions) {
        std::cout << "(" << pos.get_x() << ", " << pos.get_y() << ") ";
    }
    std::cout << std::endl;
}

Block::position_vector Block::get_occupied_cell_positions() {
    position_vector tiles = cells[rotation];
    position_vector moved_tiles;

    for (Coords& coord : tiles) {
        Coords new_coord = Coords(coord.get_x() + row_offset, coord.get_y() + col_offset);
        moved_tiles.push_back(new_coord);
    }

    return moved_tiles;
}

void Block::spawn_in_the_middle(BlockType type) {
    switch (type) {
        case BlockType::O_BLOCK:
            this->move_block(4, 0);
            break;
        case BlockType::I_BLOCK:
            this->move_block(4, -1);
            break;
        default:
            this->move_block(3, 0);
            break;
    }
}