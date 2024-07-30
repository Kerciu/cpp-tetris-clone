#include <SFML/Window.hpp>
#include <memory>
#include "TetrisGui.h"
#include "Grid.h"

void test_grid_distribution(Grid* grid) {
    auto grid_distribution = grid->get_grid_distribution();
    grid_distribution[0][0] = 1;
    grid_distribution[3][5] = 4;
    grid_distribution[17][8] = 6;
    grid->set_grid_distribution(grid_distribution);
}

int main(int argc, char** argv) {
    std::unique_ptr<TetrisGui> tetris_gui = std::make_unique<TetrisGui>("Tetris", 300, 600);
    Grid grid;
    test_grid_distribution(&grid);

    while(tetris_gui->is_running()) {
        tetris_gui->handle_events();
        tetris_gui->update();
        tetris_gui->render(grid);
    }

    return 0;
}