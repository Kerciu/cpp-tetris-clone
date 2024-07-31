#include <SFML/Window.hpp>
#include <memory>
#include "../gui/TetrisGui.h"
#include "../grid/Grid.h"
#include "../blocks/Blocks.cpp"

int main(int argc, char** argv) {
    std::unique_ptr<TetrisGui> tetris_gui = std::make_unique<TetrisGui>("Tetris", 300, 600);
    Grid grid;
    
    OBlock lb = OBlock();

    while(tetris_gui->is_running()) {
        tetris_gui->handle_events();
        tetris_gui->update();
        tetris_gui->render(grid, &lb);
    }

    return 0;
}