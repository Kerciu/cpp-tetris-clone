#include "TetrisGui.h"

TetrisGui::TetrisGui(std::string window_name, int width, int height)
    : window(sf::VideoMode(width, height), window_name),
      font_loader(FontLoader("/home/kerciu/Desktop/tetris-cpp/assets/font/Tetris.ttf"))
{
    window.setFramerateLimit(60);
}

bool TetrisGui::is_running()
{
    return window.isOpen();
}

void TetrisGui::handle_events()
{
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void TetrisGui::render(Game* game)
{
    window.clear();
    render_gui_components(game);
    game->display(&window);
    window.display();
}

void TetrisGui::render_gui_components(Game* game)
{
    draw_gradient_background();
    draw_next_block();
    draw_current_score(game->get_score().get_score());
    draw_game_over(game->is_game_over());
    draw_guiding_block(game->is_game_over());
}

void TetrisGui::draw_gradient_background()
{   
    // #522258 and #C63C51
    std::pair<sf::Color, sf::Color> hex_colors = std::make_pair(sf::Color(0x522258ff), sf::Color(0xC63C51ff));
    std::pair<int, int> size = std::make_pair(window.getSize().x, window.getSize().y);
    sf::VertexArray gradient = GradientCreator::create_gradient(hex_colors, size);
    window.draw(gradient);
}

void TetrisGui::draw_score(int score)
{
    sf::Text text;
    sf::Font font = font_loader.get_font();
    text.setFont(font);
    text.setString(get_score_as_string(score));
    text.setCharacterSize(45);
    text.setFillColor(sf::Color::White);

    sf::FloatRect text_bounds = text.getLocalBounds();

    float text_width = text_bounds.width;
    text.setPosition(
        calculate_relative_position(text_width), 295
    );

    window.draw(text);
}

int TetrisGui::calculate_relative_position(int x)
{
    return (355 + (185 - x) / 2);
}

std::string TetrisGui::get_score_as_string(int score)
{
    std::stringstream ss;
    ss << score;
    return ss.str();
}

void TetrisGui::draw_text(std::string text_to_draw, float x, float y, int char_size)
{   
    sf::Text text;
    sf::Font font = font_loader.get_font();
    text.setFont(font);
    text.setString(text_to_draw);
    text.setCharacterSize(char_size);
    text.setFillColor(sf::Color::White);
    text.setPosition(x, y);
    window.draw(text);
}

void TetrisGui::draw_next_block()
{
    draw_text("Next Block", 335, 15);
    draw_next_block_rounded_rectangle();
}

void TetrisGui::draw_current_score(int score)
{
    draw_text("SCORE", 375, 235);
    draw_score_rounded_rectangle();
    draw_score(score);
}

void TetrisGui::draw_game_over(bool game_over)
{
    if (game_over) {
        draw_text("Game Over", 340, 405);
        draw_text("PRESS ANY ARROW\n  TO CONTINUE", 340, 475, 20);
    }
}

void TetrisGui::draw_guiding_block(bool game_over)
{
    if (!game_over)
    {
        Arrow::draw_guiding_arrows(&window, 445, 425);
    }
}

void TetrisGui::draw_next_block_rounded_rectangle()
{
    RoundedRectangleDrawer::draw_rounded_rectangle(
        &window, 335, 75, 220, 120, 20, sf::Color(0xD95F59ff)
    );
}

void TetrisGui::draw_score_rounded_rectangle()
{
    RoundedRectangleDrawer::draw_rounded_rectangle(
        &window, 335, 290, 220, 70, 20, sf::Color(0xD95F59ff)
    );
}