#pragma once
#include <SFML/Audio.hpp>
#include <string>
#include "../utils/exceptions.h"

class AudioPlayer
{
    public:
    AudioPlayer(const std::string& path_to_audio_files);
    ~AudioPlayer();

    bool load_music(const std::string& file_name);
    bool load_sound(const std::string& file_name);
    void play_music();
    void play_specific_sound();
    void play_music_from(sf::Time offset);
    void stop_music();
    void set_volume(float volume);
    void set_sound_volume(float volume);
    void set_loop(bool loop);

private:
    std::string files_path;
    sf::Music music;
    sf::SoundBuffer soundBuffer;
    sf::Sound sound;
};