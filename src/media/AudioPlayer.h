#pragma once
#include <SFML/Audio.hpp>
#include <string>
#include "../utils/exceptions.h"

class AudioPlayer
{
    public:
    AudioPlayer(const std::string& path_to_audio_files);
    ~AudioPlayer();

    bool load_music();
    void play_music();
    void play_music_from(sf::Time offset);
    void set_music();
    void set_volume(float volume);
    void set_loop(bool loop);

    private:
    std::string files_path;
    sf::Music soundtrack;
};