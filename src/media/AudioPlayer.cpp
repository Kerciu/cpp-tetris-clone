#include "AudioPlayer.h"

AudioPlayer::AudioPlayer(const std::string& path_to_audio_files) : files_path(path_to_audio_files)
{
}

AudioPlayer::~AudioPlayer()
{
}

bool AudioPlayer::load_music()
{
    bool success = soundtrack.openFromFile(files_path + "Tetris Theme [NO COPYRIGHT].mp3");
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

void AudioPlayer::play_music_from(sf::Time offset)
{
    soundtrack.setPlayingOffset(offset);
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

void AudioPlayer::set_loop(bool loop)
{
    soundtrack.setLoop(loop);
}
