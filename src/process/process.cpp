#include "process.h"

Process::Process() : last_update_time(sf::Time::Zero)
{
    this->tetris_gui = std::make_unique<TetrisGui>("Tetris", 300, 600);
    this->game = Game();
}

void Process::game_loop()
{
    sf::Time fall_interval = sf::milliseconds(200);

    while(tetris_gui->is_running()) {
        game.handle_input();

        if (event_triggered(fall_interval)) {
            game.move_block_down();
        }
        tetris_gui->handle_events();
        tetris_gui->render(&game);
    }
}

bool Process::event_triggered(sf::Time interval)
{
    sf::Time elapsed = clock.getElapsedTime();

    if (elapsed - last_update_time >= interval) {
        last_update_time = elapsed;
        return true;
    }
    return false;

}
