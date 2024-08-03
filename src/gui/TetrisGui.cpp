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
    draw_gradient_background();
    draw_next_block();
    draw_current_score();
    draw_game_over(game->is_game_over());
    game->display(&window);
    window.display();
}

void TetrisGui::draw_gradient_background()
{   
    // #522258 and #C63C51
    std::pair<sf::Color, sf::Color> hex_colors = std::make_pair(sf::Color(0x522258ff), sf::Color(0xC63C51ff));
    std::pair<int, int> size = std::make_pair(window.getSize().x, window.getSize().y);
    sf::VertexArray gradient = GradientCreator::create_gradient(hex_colors, size);
    window.draw(gradient);
}

void TetrisGui::draw_text(std::string text_to_draw, float x, float y)
{   
    sf::Text text;
    sf::Font font = font_loader.get_font();
    text.setFont(font);
    text.setString(text_to_draw);
    text.setCharacterSize(38);
    text.setFillColor(sf::Color::White);
    text.setPosition(x, y);
    window.draw(text);
}

void TetrisGui::draw_next_block()
{
    draw_text("Next Block", 335, 15);
    draw_next_block_rounded_rectangle();
}

void TetrisGui::draw_current_score()
{
    draw_text("SCORE", 370, 235);
    draw_score_rounded_rectangle();
}

void TetrisGui::draw_game_over(bool game_over)
{
    if (game_over) {
        draw_text("Game Over", 335, 405);
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