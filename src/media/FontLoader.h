#pragma once
#include <SFML/Graphics.hpp>

class FontLoader 
{
    public:
    FontLoader(std::string file_handle);

    sf::Font get_font();

private:
    std::string file_handle;
    sf::Font font;

    void load_font();
};
