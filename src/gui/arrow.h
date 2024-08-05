#pragma once
#include <SFML/Graphics.hpp>
#include "../media/FontLoader.h"

class Arrow
{
    public:
    static void draw_guiding_arrows(sf::RenderWindow* window, float x, float y);

    private:
    static void combine_arrow_w_text(sf::RenderWindow* window, float x, float y);
    static void draw_arrow(sf::RenderWindow* window, float x, float y, float shaft_x, float shaft_y, float rotation);
    static void draw_guiding_text(sf::RenderWindow* window, float x, float y, const std::string& text, float offsetX, float offsetY);
};