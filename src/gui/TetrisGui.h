#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include <sstream>
#include "../grid/Grid.h"
#include "../game/Game.h"
#include "../media/FontLoader.h"
#include "gui_components/RoundedRectangleDrawer.h"
#include "gui_components/GradientCreator.h"
#include "gui_components/Arrow.h"

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

    void render_gui_components(Game *game);

    void draw_gradient_background();
    void draw_text(std::string text_to_draw, float x, float y, int char_size=48);
    void draw_score(int score);
    int calculate_relative_position(int x);
    std::string get_score_as_string(int score);
    void draw_next_block();
    void draw_current_score(int score);
    void draw_game_over(bool game_over);
    void draw_guiding_block(bool game_over);
    void draw_next_block_rounded_rectangle();
    void draw_score_rounded_rectangle();
};