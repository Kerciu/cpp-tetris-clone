#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

extern const sf::Color dark_grey;
extern const sf::Color green;
extern const sf::Color red;
extern const sf::Color orange;
extern const sf::Color yellow;
extern const sf::Color magenta;
extern const sf::Color cyan;
extern const sf::Color blue;
extern const int OFFSET = 1;

std::vector<sf::Color> get_cell_colors();