#include "AudioPlayer.h"

AudioPlayer::AudioPlayer(const std::string& file_handle) : file_handle(file_handle)
{
}

AudioPlayer::~AudioPlayer()
{
}

bool AudioPlayer::load_music()
{
    bool success = soundtrack.openFromFile(file_handle);
    if (!success) 
    {
        throw AudioLoadingFailure();
        return false;
    }
    return true;
}

void AudioPlayer::play_music()
{
    soundtrack.play();
}

void AudioPlayer::set_music()
{
    soundtrack.stop();
}

void AudioPlayer::set_volume(float volume)
{
    soundtrack.setVolume(volume);
}
