#include <array>
#include <SFML/Graphics.hpp>

class Grid {
    public:
    Grid();
    ~Grid() = default;

    void draw_grid_rectangle(int row, int col);
    void display();

    private:
    std::array<std::array<int, 10>, 20> grid_distribution;
    std::vector<sf::Color> grid_colors;
    int num_rows;
    int num_cols;
    int cell_size;
    

    void initialize_grid();
    std::vector<sf::Color> initialize_colors();
};