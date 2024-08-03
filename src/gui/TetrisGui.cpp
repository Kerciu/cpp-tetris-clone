#include "TetrisGui.h"

TetrisGui::TetrisGui(std::string window_name, int width, int height)
    : window(sf::VideoMode(width, height), window_name)
{
    window.setFramerateLimit(60);
    
}

bool TetrisGui::is_running()
{
    return window.isOpen();
}

void TetrisGui::handle_events()
{
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void TetrisGui::render(Game* game)
{
    window.clear();
    draw_gradient_background();
    game->display(&window);
    window.display();
}

void TetrisGui::draw_gradient_background()
{   
    // #522258 and #C63C51
    std::pair<int, int> hex_colors = std::make_pair(0x522258ff, 0xC63C51ff);
    std::pair<int, int> size = std::make_pair(window.getSize().x, window.getSize().y);
    sf::VertexArray gradient = create_gradient(hex_colors, size);
    window.draw(gradient);
}

sf::VertexArray TetrisGui::create_gradient(std::pair<int, int> hex_colors, std::pair<int, int> selected_size)
{
    sf::VertexArray gradient(sf::TrianglesStrip, 4);

    sf::Color top_left_color = sf::Color(hex_colors.first);     
    sf::Color bottom_right_color = sf::Color(hex_colors.second);

    distribute_gradient(&gradient, std::make_pair(top_left_color, bottom_right_color), selected_size);

    return gradient;
}

void TetrisGui::distribute_gradient(sf::VertexArray* gradient, std::pair<sf::Color, sf::Color> colors, std::pair<int, int> selected_size)
{
    (*gradient)[0] = sf::Vertex(sf::Vector2f(0, 0), colors.first);
    (*gradient)[1] = sf::Vertex(sf::Vector2f(0, selected_size.second), colors.second);
    (*gradient)[2] = sf::Vertex(sf::Vector2f(selected_size.first, 0), colors.first);
    (*gradient)[3] = sf::Vertex(sf::Vector2f(selected_size.first, selected_size.second), colors.second);
}
