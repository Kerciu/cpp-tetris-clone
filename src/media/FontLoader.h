#pragma once
#include <SFML/Graphics.hpp>

class FontLoader 
{
    public:
    FontLoader(std::string file_handle);

    private:
    std::string file_handle;
    sf::Font font;

    void load_font();
};
