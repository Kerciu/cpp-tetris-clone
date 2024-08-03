#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include "Grid.h"
#include "../game/game.h"

class TetrisGui {
    public:
    TetrisGui(std::string window_name, int width, int height);
    ~TetrisGui() = default;

    bool is_running();
    void handle_events();
    void render(Game* game);

    static sf::VertexArray create_gradient(std::pair<int, int> hex_colors, std::pair<int, int> size);

    private:
    sf::RenderWindow window;

    void draw_gradient_background();
    static void distribute_gradient(sf::VertexArray* gradient, std::pair<sf::Color, sf::Color> colors, std::pair<int, int> selected_size);
};