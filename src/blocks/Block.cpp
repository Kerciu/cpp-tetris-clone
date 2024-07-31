#include "Block.h"

Block::Block()
{
    cell_size = 30;
    rotation = 0;
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

void Block::initialize_posiiton_states() {
        std::vector<position_vector> position_vec = create_position_vec();
        for (int i = 0; i < 4; ++i)
            (*this->get_cells_ptr())[i] = position_vec[i];
}

void Block::draw_block(sf::RenderWindow* window) {
        position_vector tiles = (*this->get_cells_ptr())[get_rotation_state()];
        int cell_size = this->get_cell_size();

        for (Coords& coord : tiles) {
            int x_coord = coord.get_x() * cell_size + OFFSET;
            int y_coord = coord.get_y() * cell_size + OFFSET;
            int width, height;
            width = height = cell_size - OFFSET;
            sf::Color color = get_cell_colors()[this->get_block_id()];

            sf::RectangleShape rectangle(sf::Vector2f(width, height));

            rectangle.setFillColor(color);
            rectangle.setPosition(sf::Vector2f(x_coord, y_coord));
            window->draw(rectangle);
        }
    }