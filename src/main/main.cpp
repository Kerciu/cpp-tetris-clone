#include <SFML/Window.hpp>
#include <memory>
#include "../gui/TetrisGui.h"
#include "../game/game.h"

double last_update_time;

bool event_triggered(double interval)
{
    double current_time = sf::Time::asMilliseconds();

    if (current_time - last_update_time >= interval) {
        last_update_time = current_time;
        return true;
    }
    return false;

}

int main(int argc, char** argv) {
    std::unique_ptr<TetrisGui> tetris_gui = std::make_unique<TetrisGui>("Tetris", 300, 600);

    Game game = Game();

    while(tetris_gui->is_running()) {
        game.handle_input();
        if (event_triggered(0.2)) {
            game.move_block_down();
        }
        tetris_gui->handle_events();
        tetris_gui->update();
        tetris_gui->render(&game);
    }

    return 0;
}