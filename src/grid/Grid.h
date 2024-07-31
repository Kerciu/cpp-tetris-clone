#pragma once
#include <array>
#include <SFML/Graphics.hpp>
#include "Coords.h"

class Grid {
    public:
    typedef std::array<std::array<int, 10>, 20> distribution;
    typedef std::vector<sf::Color> color_vector;

    Grid();
    ~Grid() = default;

    void display(sf::RenderWindow* window);
    distribution get_grid_distribution();
    color_vector get_colors();
    void set_grid_distribution(distribution new_distribution);
    void set_colors(color_vector new_grid_colors);
    int get_num_rows();
    int get_num_cols();

    private:
    distribution grid_distribution;
    color_vector grid_colors;
    static const int OFFSET = 1;
    static const int num_rows = 20;
    static const int num_cols = 10;
    static const int cell_size = 30;
    
    void initialize_grid();
    std::vector<sf::Color> initialize_colors();
    void draw_grid_rectangle(sf::RenderWindow* window, int row, int col);
    sf::RectangleShape create_rectangle(int row, int col);
};