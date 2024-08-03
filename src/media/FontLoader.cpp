#include "FontLoader.h"

FontLoader::FontLoader(std::string file_handle)
{
    this->file_handle = file_handle;
    this->font = sf::Font();

    this->load_font();
}

void FontLoader::load_font()
{
    bool success = font.loadFromFile(file_handle);
    if (!success) throw std::out_of_range("Error: font did not load properly");
}
