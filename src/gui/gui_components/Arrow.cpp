#include "Arrow.h"

void Arrow::draw_guiding_arrows(sf::RenderWindow* window, float x, float y)
{
    combine_arrow_w_text(window, x, y);
}

void Arrow::combine_arrow_w_text(sf::RenderWindow* window, float x, float y)
{
    float obj_spacing = 80.0f;
    float shaft_spacing = 20.0f;
    float text_spacing = 120.0f;

    draw_arrow(window, x, y, x, y + shaft_spacing, 0);            // rotate
    draw_arrow(window, x, y + 2* obj_spacing/1.5, x, y + 2* obj_spacing/1.5 - shaft_spacing, 180); // move down
    draw_arrow(window, x + obj_spacing / 1.5, y + obj_spacing/1.5, x + obj_spacing / 1.5 - shaft_spacing, y + obj_spacing / 1.5, 90); // move right
    draw_arrow(window, x - obj_spacing / 1.5, y + obj_spacing/1.5, x - obj_spacing / 1.5 + shaft_spacing, y + obj_spacing / 1.5, 270); // move left

    draw_guiding_text(window, x, y, "Rotate", -25, -55);
    draw_guiding_text(window, x, y + text_spacing, "Move Down", -40, 20);
    draw_guiding_text(window, x + text_spacing, y + text_spacing/2, "Move Right", -72, -55);
    draw_guiding_text(window, x - text_spacing, y + text_spacing/2, "Move Left", 0, -55);
}

void Arrow::draw_arrow(sf::RenderWindow* window, float x, float y, float shaft_x, float shaft_y, float rotation)
{
    sf::CircleShape triangle(30, 3);
    triangle.setFillColor(sf::Color(0xD95F59ff));
    triangle.setPosition(x, y);
    triangle.setOrigin(30, 30);
    triangle.setRotation(rotation);

    sf::RectangleShape shaft(sf::Vector2f(20, 20));
    shaft.setFillColor(sf::Color(0xD95F59ff));
    shaft.setPosition(shaft_x, shaft_y);
    shaft.setOrigin(10, 10);
    shaft.setRotation(rotation);

    window->draw(shaft);
    window->draw(triangle);
}

void Arrow::draw_guiding_text(sf::RenderWindow* window, float x, float y, const std::string& text, float offsetX, float offsetY)
{   
    float offset = 30.0f;
    sf::Text text_obj;
    FontLoader font_loader("../assets/font/fortnite.otf");
    sf::Font font = font_loader.get_font();
    text_obj.setString(text);
    text_obj.setFont(font);
    text_obj.setCharacterSize(20);

    text_obj.setFillColor(sf::Color::White);
    text_obj.setPosition(x + offsetX, y + offsetY);

    window->draw(text_obj);
}
