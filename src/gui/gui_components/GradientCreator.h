#pragma once
#include <SFML/Graphics.hpp>

class GradientCreator
{
    public:
    static sf::VertexArray create_gradient(std::pair<sf::Color, sf::Color> hex_colors, std::pair<int, int> selected_size);

    private:
    static void distribute_gradient(sf::VertexArray* gradient, std::pair<sf::Color, sf::Color> colors, std::pair<int, int> selected_size);

};