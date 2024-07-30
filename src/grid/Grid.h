#pragma once
#include <array>
#include <SFML/Graphics.hpp>
#include "Coords.h"

class Grid {
    public:
    Grid();
    ~Grid() = default;

    void display(sf::RenderWindow* window);

    private:
    std::array<std::array<int, 10>, 20> grid_distribution;
    std::vector<sf::Color> grid_colors;
    static const int OFFSET = 1;
    static const int num_rows = 20;
    static const int num_cols = 10;
    static const int cell_size = 30;
    
    void initialize_grid();
    std::vector<sf::Color> initialize_colors();
    void draw_grid_rectangle(sf::RenderWindow* window, int row, int col);
    sf::RectangleShape create_rectangle(int row, int col);
};