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

void TetrisGui::render(Grid grid, Block* block)
{
    window.clear(sf::Color(44, 44, 127, 255));
    grid.display(&window);
    block->draw_block(&window);
    window.display();
}

void TetrisGui::update()
{
}
