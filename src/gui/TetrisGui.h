#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include "Grid.h"
#include "../blocks/Block.h"

class TetrisGui {
    public:
    TetrisGui(std::string window_name, int width, int height);
    ~TetrisGui() = default;

    bool is_running();
    void handle_events();
    void update();
    void render(Grid grid, Block* block);

    private:
    sf::RenderWindow window;
};