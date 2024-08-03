#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include "Grid.h"
#include "../game/game.h"
#include "../media/FontLoader.h"
#include "rounded_rectangle.h"
#include "gradient.h"

class TetrisGui {
    public:
    TetrisGui(std::string window_name, int width, int height);
    ~TetrisGui() = default;

    bool is_running();
    void handle_events();
    void render(Game* game);

    private:
    sf::RenderWindow window;
    FontLoader font_loader;

    void draw_gradient_background();
    void draw_text(std::string text_to_draw, float x, float y);
    void draw_next_block();
    void draw_current_score();
    void draw_next_block_rounded_rectangle();
    void draw_score_rounded_rectangle();
};