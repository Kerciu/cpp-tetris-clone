#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "../gui/TetrisGui.h"
#include "../game/game.h"

class Process {
    public:
    Process();
    void game_loop();

private:
    std::unique_ptr<TetrisGui> tetris_gui;
    Game game;
    sf::Time last_update_time;
    sf::Clock clock;

    bool event_triggered(sf::Time interval);
};