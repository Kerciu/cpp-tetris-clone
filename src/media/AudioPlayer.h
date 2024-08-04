#pragma once
#include <SFML/Audio.hpp>
#include <string>
#include "../utils/exceptions.h"

class AudioPlayer
{
    public:
    AudioPlayer(const std::string& file_handle);
    ~AudioPlayer();

    bool load_music();
    void play_music();
    void set_music();
    void set_volume(float volume);

    private:
    std::string file_handle;
    sf::Music soundtrack;
};