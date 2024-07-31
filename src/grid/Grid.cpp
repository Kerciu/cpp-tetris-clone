#include "Grid.h"
#include "../colors/colors.h"

Grid::Grid()
{
    initialize_grid();
    grid_colors = get_cell_colors();
}

void Grid::display(sf::RenderWindow* window)
{
    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            draw_grid_rectangle(window, i, j);
        }
    }
}

void Grid::draw_grid_rectangle(sf::RenderWindow* window, int row, int col) {
    sf::RectangleShape rectangle = create_rectangle(row, col);
    window->draw(rectangle);
}

sf::RectangleShape Grid::create_rectangle(int row, int col) {
    int cell_val = grid_distribution[row][col];
    sf::Color current_color = grid_colors[cell_val];
    Coords coords(col * cell_size + OFFSET, row * cell_size + OFFSET);

    sf::RectangleShape rectangle(sf::Vector2f(cell_size - OFFSET, cell_size - OFFSET));

    rectangle.setFillColor(current_color);
    rectangle.setPosition(sf::Vector2f(coords.get_x(), coords.get_y()));
    return rectangle;
}

void Grid::initialize_grid()
{
    for (auto& row : grid_distribution) {
        row.fill(0);
    }
}

Grid::distribution Grid::get_grid_distribution() {
    return grid_distribution;
}

void Grid::set_grid_distribution(distribution new_distribution) {
    grid_distribution = new_distribution;
}

void Grid::set_colors(color_vector new_grid_colors) {
    grid_colors = new_grid_colors;
}

Grid::color_vector Grid::get_colors()
{
    return grid_colors;
}

int Grid::get_num_rows()
{
    return num_rows;
}

int Grid::get_num_cols()
{
    return num_cols;
}
