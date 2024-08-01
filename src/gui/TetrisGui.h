#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include "Grid.h"
#include "../process/process.h"

class TetrisGui {
    public:
    TetrisGui(std::string window_name, int width, int height);
    ~TetrisGui() = default;

    bool is_running();
    void handle_events();
    void update();
    void render(Process* process);

    private:
    sf::RenderWindow window;
};