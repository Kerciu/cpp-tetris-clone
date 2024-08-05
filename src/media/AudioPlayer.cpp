#include "AudioPlayer.h"

AudioPlayer::AudioPlayer(const std::string& path_to_audio_files) : files_path(path_to_audio_files)
{
}

AudioPlayer::~AudioPlayer()
{
}

bool AudioPlayer::load_music(const std::string& file_name) {
    if (!music.openFromFile(files_path + file_name)) {
        std::cerr << "Failed to load music from: " << files_path + file_name << std::endl;
        return false;
    }
    return true;
}

bool AudioPlayer::load_sound(const std::string& file_name) {
    if (!soundBuffer.loadFromFile(files_path + file_name)) {
        std::cerr << "Failed to load sound from: " << files_path + file_name << std::endl;
        return false;
    }
    sound.setBuffer(soundBuffer);
    return true;
}

void AudioPlayer::play_music() {
    music.play();
}

void AudioPlayer::play_specific_sound() {
    sound.play();
}

void AudioPlayer::play_music_from(sf::Time offset) {
    music.setPlayingOffset(offset);
    music.play();
}

void AudioPlayer::stop_music() {
    music.stop();
}

void AudioPlayer::set_volume(float volume) {
    music.setVolume(volume);
}

void AudioPlayer::set_sound_volume(float volume)
{
    sound.setVolume(volume);
}

void AudioPlayer::set_loop(bool loop) {
    music.setLoop(loop);
}

bool AudioPlayer::is_playing()
{
    return music.getStatus() == sf::Music::Playing;
}
