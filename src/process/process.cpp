#include "process.h"

Process::Process() : last_update_time(sf::Time::Zero), audio_player(AudioPlayer("/home/kerciu/Desktop/tetris-cpp/assets/sound/")), game(Game())
{
    this->tetris_gui = std::make_unique<TetrisGui>("Tetris", 580, 620);
}

void Process::play_music()
{
    try {
        audio_player.load_music("tetris-theme.mp3");
        audio_player.set_volume(50);

        audio_player.play_music_from(sf::seconds(5));
        audio_player.set_loop(true);

    } catch (const AudioLoadingFailure& e) {
        std::cerr << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Process::stop_music_if_game_over()
{
    if (game.is_game_over()) {
        audio_player.stop_music();
    }
    else {
        if (!audio_player.is_playing()) {
            play_music();
        }
    }
}

void Process::reset_music()
{
    audio_player.stop_music();
    play_music();
}

void Process::play_start_sound()
{
    if (!audio_player.load_sound("game-start.mp3")) {
        std::cerr << "Failed to load game start sound" << std::endl;
    } else {
        audio_player.set_sound_volume(15);
        audio_player.play_specific_sound();
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

        stop_music_if_game_over();
        
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
