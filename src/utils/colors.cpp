#include "colors.h"

const sf::Color dark_grey = sf::Color(0x373A40ff);
const sf::Color green = sf::Color(0xDEF9C4ff);
const sf::Color red = sf::Color(0xF5004Fff);
const sf::Color orange = sf::Color(0xFFB200ff);
const sf::Color yellow = sf::Color(0xF6FB7Aff);
const sf::Color magenta = sf::Color(0xB692C2ff);
const sf::Color cyan = sf::Color(0x59D5E0ff);
const sf::Color blue = sf::Color(0x3ABEF9ff);
const int OFFSET = 1;


std::vector<sf::Color> get_cell_colors()
{
    return {dark_grey, green, red, orange, yellow, magenta, cyan, blue};
}

sf::Color get_appropriate_gradient_color(sf::Color top_color)
{
    if (top_color == dark_grey)
        return sf::Color(0x686D76ff);
    else if (top_color == green)
        return sf::Color(0x50B498ff);
    else if (top_color == red)
        return sf::Color(0xEF5A6Fff);
    else if (top_color == orange)
        return sf::Color(0xEB5B00ff);
    else if (top_color == yellow)
        return sf::Color(0xFFDE4Dff);
    else if (top_color == magenta)
        return sf::Color(0xFF4E88ff);
    else if (top_color == cyan)
        return sf::Color(0x8DDFCBff);
    else if (top_color == blue)
        return sf::Color(0x050C9Cff);
    else
        return sf::Color::Transparent;
}
