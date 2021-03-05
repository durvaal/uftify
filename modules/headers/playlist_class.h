#ifndef __PLAYLIST_CLASS_H_
#define __PLAYLIST_CLASS_H_

#include "song_class.h"

class Playlist {
    private:
        char name[50];

    public:
        Playlist();
        ~Playlist();

        void setName(char name[50]);
        char* getName();

        class Song song;
        class Playlist *node;
};

#endif