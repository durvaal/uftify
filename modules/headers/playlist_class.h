#ifndef __PLAYLIST_CLASS_H_
#define __PLAYLIST_CLASS_H_

#include <array>
#include <string>
#include "song_class.h"

class Playlist {
    private:
        char name[50];
        std::array<Song, 20> songs;

    public:
        Playlist();
        ~Playlist();

        void setName(char name[50]);
        char* getName();
        void setSong(Song song);
        Song getSong(char name[50]);
        std::array<Song, 20> getSongs();
        class Playlist *node;
};

#endif