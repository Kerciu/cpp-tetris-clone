#include "process.h"

Process::Process() : last_update_time(sf::Time::Zero), audio_player(AudioPlayer("/home/kerciu/Desktop/tetris-cpp/assets/sound/"))
{
    this->tetris_gui = std::make_unique<TetrisGui>("Tetris", 580, 620);
    this->game = Game();
}

void Process::play_music()
{
    try {
        audio_player.load_music();
        audio_player.set_volume(50);

        audio_player.play_music(sf::seconds(30));
        audio_player.set_loop(true);
    } catch (const AudioLoadingFailure& e) {
        std::cerr << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
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
