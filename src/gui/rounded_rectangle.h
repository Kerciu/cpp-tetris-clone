#pragma once
#include <SFML/Graphics.hpp>
#include "gradient.h"

class RoundedRectangleDrawer
{
    public:
    static void draw_rounded_rectangle(sf::RenderWindow* window, float x, float y, float width, float height, float radius, sf::Color fillColor);

    private:
    static sf::CircleShape create_corner(float radius, int pointCount, sf::Color color, float posX, float posY);
    static sf::RectangleShape create_side(float width, float height, sf::Color color, float posX, float posY);
};