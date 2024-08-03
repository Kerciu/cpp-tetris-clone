#include "rounded_rectangle.h"

void RoundedRectangleDrawer::draw_rounded_rectangle(sf::RenderWindow* window, float x, float y, float width, float height, float radius, sf::Color fillColor)
{
    const int pointCount = 100;

    sf::CircleShape topLeftCorner = create_corner(radius, pointCount, fillColor, x, y);
    sf::CircleShape topRightCorner = create_corner(radius, pointCount, fillColor, x + width - radius * 2, y);
    sf::CircleShape bottomLeftCorner = create_corner(radius, pointCount, fillColor, x, y + height - radius * 2);
    sf::CircleShape bottomRightCorner = create_corner(radius, pointCount, fillColor, x + width - radius * 2, y + height - radius * 2);

    sf::RectangleShape main_rect(sf::Vector2f(width - 2 * radius, height - 2 * radius));
    main_rect.setPosition(x + radius, y + radius);
    main_rect.setFillColor(fillColor);

    sf::RectangleShape leftRect = create_side(radius, height - 2 * radius, fillColor, x, y + radius);
    sf::RectangleShape rightRect = create_side(radius, height - 2 * radius, fillColor, x + width - radius, y + radius);
    sf::RectangleShape topRect = create_side(width - 2 * radius, radius, fillColor, x + radius, y);
    sf::RectangleShape bottomRect = create_side(width - 2 * radius, radius, fillColor, x + radius, y + height - radius);

    window->draw(main_rect);
    window->draw(leftRect);
    window->draw(rightRect);
    window->draw(topRect);
    window->draw(bottomRect);
    window->draw(topLeftCorner);
    window->draw(topRightCorner);
    window->draw(bottomLeftCorner);
    window->draw(bottomRightCorner);
}

sf::CircleShape RoundedRectangleDrawer::create_corner(float radius, int pointCount, sf::Color color, float posX, float posY)
{
    sf::CircleShape corner(radius, pointCount);
    corner.setFillColor(color);
    corner.setPosition(posX, posY);
    return corner;
}

sf::RectangleShape RoundedRectangleDrawer::create_side(float width, float height, sf::Color color, float posX, float posY)
{
    sf::RectangleShape side(sf::Vector2f(width, height));
    side.setFillColor(color);
    side.setPosition(posX, posY);
    return side;
}
