#include "GradientCreator.h"

sf::VertexArray GradientCreator::create_gradient(std::pair<sf::Color, sf::Color> hex_colors, std::pair<int, int> selected_size)
{
    sf::VertexArray gradient(sf::TrianglesStrip, 4);

    distribute_gradient(&gradient, hex_colors, selected_size);

    return gradient;
}

void GradientCreator::distribute_gradient(sf::VertexArray* gradient, std::pair<sf::Color, sf::Color> colors, std::pair<int, int> selected_size)
{
    (*gradient)[0] = sf::Vertex(sf::Vector2f(0, 0), colors.first);
    (*gradient)[1] = sf::Vertex(sf::Vector2f(0, selected_size.second), colors.second);
    (*gradient)[2] = sf::Vertex(sf::Vector2f(selected_size.first, 0), colors.first);
    (*gradient)[3] = sf::Vertex(sf::Vector2f(selected_size.first, selected_size.second), colors.second);
}
