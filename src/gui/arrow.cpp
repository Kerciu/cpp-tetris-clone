#include "arrow.h"

void Arrow::draw_guiding_arrows(sf::RenderWindow* window, float x, float y)
{
    combine_arrow_w_text(window, x, y);
}

void Arrow::combine_arrow_w_text(sf::RenderWindow* window, float x, float y)
{
    float arrow_spacing = 100.0f;
    float text_spacing = 120.0f;

    draw_arrow(window, x, y, 0);            // rotate
    draw_arrow(window, x, y + 2* arrow_spacing/1.5, 180); // move down
    draw_arrow(window, x + arrow_spacing / 1.5, y + arrow_spacing/1.5, 90); // move right
    draw_arrow(window, x - arrow_spacing / 1.5, y + arrow_spacing/1.5, 270); // move left

    draw_guiding_text(window, x, y, "Rotate", -25, -55);
    draw_guiding_text(window, x, y + text_spacing, "Move Down", -45, 45);
    draw_guiding_text(window, x + text_spacing, y + text_spacing/2, "Move Right", -85, 35);
    draw_guiding_text(window, x - text_spacing, y + text_spacing/2, "Move Left", 0, -40);
}

void Arrow::draw_arrow(sf::RenderWindow* window, float x, float y, float rotation)
{
    sf::CircleShape triangle(30, 3);
    triangle.setFillColor(sf::Color::White);
    triangle.setPosition(x, y);
    triangle.setOrigin(30, 30);
    triangle.setRotation(rotation);

    window->draw(triangle);
}

void Arrow::draw_guiding_text(sf::RenderWindow* window, float x, float y, const std::string& text, float offsetX, float offsetY)
{   
    float offset = 30.0f;
    sf::Text text_obj;
    FontLoader font_loader("/home/kerciu/Desktop/tetris-cpp/assets/font/Tetris.ttf");
    sf::Font font = font_loader.get_font();
    text_obj.setString(text);
    text_obj.setFont(font);
    text_obj.setCharacterSize(15);

    text_obj.setFillColor(sf::Color::White);
    text_obj.setPosition(x + offsetX, y + offsetY);

    window->draw(text_obj);
}
