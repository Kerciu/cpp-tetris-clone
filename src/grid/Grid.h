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
    int num_rows;
    int num_cols;
    int cell_size;
    

    void initialize_grid();
    std::vector<sf::Color> initialize_colors();
    void draw_grid_rectangle(sf::RenderWindow* window, int row, int col);
    sf::RectangleShape Grid::create_rectangle(int row, int col);
};