#include "Grid.h"

Grid::Grid()
{
    num_rows = 20;
    num_cols = 10;
    cell_size = 30;
    initialize_grid();
    grid_colors = initialize_colors();
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
    Coords coords(col * cell_size, row * cell_size);

    sf::RectangleShape rectangle(sf::Vector2f(cell_size, cell_size));

    rectangle.setFillColor(current_color);
    rectangle.setPosition(coords.get_x(), coords.get_y());
    return rectangle;
}

void Grid::initialize_grid()
{
    std::fill(grid_distribution.begin(), grid_distribution.end(), 0);
}

std::vector<sf::Color> Grid::initialize_colors() {
    return {
        sf::Color(26, 31, 40, 255), // dark grey
        sf::Color::Green,           // green
        sf::Color::Red,             // red
        sf::Color(226, 116, 17, 255), // orange
        sf::Color::Yellow,          // yellow
        sf::Color::Magenta,         // magenta
        sf::Color::Cyan,            // cyan
        sf::Color::Blue             // blue
    };
}
