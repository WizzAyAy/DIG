#pragma once
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QSound>
#include <vector>
#include <string>

/*
 *  Class qui gere la musique et les sons
*/

struct sounds{
    QSound* sound;
    std::string soundName;
};

class music : public QMediaPlayer
{
public:
    music();
    void initPlayList();
    void initSound();

    void nextMusic();
    void playSound(std::string const & name);

private:
    QMediaPlaylist* _playList;
    std::vector<sounds> _sounds;
};
