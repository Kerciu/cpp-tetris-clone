#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "../gui/TetrisGui.h"
#include "../game/game.h"
#include "../media/AudioPlayer.h"

class Process {
    public:
    Process();
    void game_loop();
    void play_music();

    void play_start_sound();

private:
    std::unique_ptr<TetrisGui> tetris_gui;
    Game game;
    AudioPlayer audio_player;
    sf::Time last_update_time;
    sf::Clock clock;

    bool event_triggered(sf::Time interval);
};