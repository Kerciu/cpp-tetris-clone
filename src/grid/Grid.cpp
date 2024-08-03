#include "Grid.h"

Grid::Grid()
{
    initialize_grid();
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

bool Grid::is_row_full(int row)
{
    for (int col = 0; col < num_cols; ++col)
    {
        if (grid_distribution[row][col] == 0)
        {
            return false;
        }
    }

    return true;
}

void Grid::clear_row(int row)
{
    for (int col = 0; col < num_cols; ++col)
    {
        grid_distribution[row][col] = 0;
    }
}

void Grid::move_row_down(int row, int rows_num)
{
    for (int col = 0; col < num_cols; ++col)
    {
        grid_distribution[row + rows_num][col] = grid_distribution[row][col];
        grid_distribution[row][col] = 0;
    }
}

sf::RectangleShape Grid::create_rectangle(int row, int col) {
    int cell_val = grid_distribution[row][col];
    sf::Color current_color = grid_colors[cell_val];
    Coords coords(row * cell_size + OFFSET + PX_OFFSET, col * cell_size + OFFSET + PX_OFFSET);

    sf::RectangleShape rectangle(sf::Vector2f(cell_size - OFFSET, cell_size - OFFSET));

    rectangle.setFillColor(current_color);
    rectangle.setPosition(sf::Vector2f(coords.get_x(), coords.get_y()));
    return rectangle;
}

void Grid::initialize_grid()
{
    for (int row = 0; row < num_rows; ++row) {
        for (int col = 0; col < num_cols; ++col) {
            grid_distribution[row][col] = 0;
        }
    }

    this->grid_colors = get_cell_colors();
}

void Grid::print_grid_to_console()
{
    for (int row = 0; row < num_rows; row++)
    {
        for (int column = 0; column < num_cols; column++)
        {
            std::cout << grid_distribution[row][column] << " ";
        }
        std::cout << std::endl;
    }
}

Grid::distribution* Grid::get_grid_distribution() {
    return &grid_distribution;
}

void Grid::set_grid_distribution(distribution new_distribution)
{
    this->grid_distribution = new_distribution;
}

void Grid::set_colors(color_vector new_grid_colors) {
    grid_colors = new_grid_colors;
}

Grid::color_vector Grid::get_colors()
{
    return grid_colors;
}

bool Grid::is_cell_empty(int row, int col)
{
    return (grid_distribution[row][col] == 0);
}

int Grid::clear_full_rows()
{
    int completed = 0;
    for (int row = num_rows - 1; row >= 0; --row)
    {
        if (is_row_full(row)) {
            clear_row(row);
            ++completed;
        }
        else if (completed > 0) {
            move_row_down(row, completed);
        }
    }
    
    return completed;
}

int Grid::get_num_rows()
{
    return num_rows;
}

int Grid::get_num_cols()
{
    return num_cols;
}

bool Grid::validate_bounds(int row, int col)
{
    return (col >= 0 && col < num_cols) && (row >= 0 && row < num_rows);
}
