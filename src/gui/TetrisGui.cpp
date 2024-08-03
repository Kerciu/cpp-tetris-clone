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
    std::pair<sf::Color, sf::Color> hex_colors = std::make_pair(sf::Color(0x522258ff), sf::Color(0xC63C51ff));
    std::pair<int, int> size = std::make_pair(window.getSize().x, window.getSize().y);
    sf::VertexArray gradient = GradientCreator::create_gradient(hex_colors, size);
    window.draw(gradient);
}
