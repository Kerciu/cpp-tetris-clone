#include "colors.h"

const sf::Color dark_grey = {26, 31, 40};
const sf::Color green = sf::Color::Green;
const sf::Color red = sf::Color::Red;
const sf::Color orange = {226, 116, 17};
const sf::Color yellow = sf::Color::Yellow;
const sf::Color magenta = sf::Color::Magenta;
const sf::Color cyan = sf::Color::Cyan;
const sf::Color blue = sf::Color::Blue;


std::vector<sf::Color> get_cell_colors()
{
    return {dark_grey, green, red, orange, yellow, magenta, cyan, blue};
}