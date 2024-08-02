#include "process.h"

Process::Process() : last_update_time(0)
{
    this->tetris_gui = std::make_unique<TetrisGui>("Tetris", 300, 600);
    this->game = Game();
}

void Process::game_loop()
{
    while(tetris_gui->is_running()) {
        game.handle_input();
        if (event_triggered(200)) {
            game.move_block_down();
        }
        tetris_gui->handle_events();
        tetris_gui->render(&game);
    }
}

bool Process::event_triggered(double interval)
{
    sf::Time elapsed = clock.getElapsedTime();
    double current_time = elapsed.asMilliseconds();

    if (current_time - last_update_time >= interval) {
        last_update_time = current_time;
        clock.restart();
        return true;
    }
    return false;

}
