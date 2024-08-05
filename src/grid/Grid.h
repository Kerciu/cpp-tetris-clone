#pragma once
#include <array>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../utils/Coords.h"
#include "../utils/ColorCreator.h"
#include "../gui/gui_components/GradientCreator.h"

class Grid {
    public:
    typedef std::array<std::array<int, 10>, 20> distribution;
    typedef std::vector<sf::Color> color_vector;

    Grid();
    ~Grid() = default;

    void display(sf::RenderWindow* window);
    void print_grid_to_console();
    distribution* get_grid_distribution();
    void set_grid_distribution(distribution new_distribution);
    void set_colors(color_vector new_grid_colors);
    color_vector get_colors();
    bool is_cell_empty(int row, int col);
    int clear_full_rows();
    int get_num_rows();
    int get_num_cols();

    bool validate_bounds(int row, int col);
    void initialize_grid();

    bool operator==(const Grid& other) const;
    bool operator!=(const Grid& other) const;

    private:
    
    distribution grid_distribution;
    color_vector grid_colors;
    static const int num_rows = 20;
    static const int num_cols = 10;
    static const int cell_size = 30;
    
    void draw_grid_rectangle(sf::RenderWindow *window, int row, int col);
    void draw_rectangle_if_gradient(sf::RenderWindow *window, int row, int col);
    bool is_row_full(int row);
    void clear_row(int row);
    void move_row_down(int row, int rows_num);
    sf::RectangleShape create_rectangle(int row, int col);
};