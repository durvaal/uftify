#include <array>
#include <string.h>
#include "./headers/playlist_class.h"

void Playlist::setName(char name[50]) {
  strncpy(this->name, name, 50);
}

char* Playlist::getName() {
  return this->name;
}

void Playlist::setSong(Song song) {
  for (int i = 0; i < 50; i++) {
    if (!this->songs[i].getName()) {
      i++;
    } else {
      this->songs[i] = song;
      break;
    }
  }
}

Song Playlist::getSong(char name[50]) {
  for (int i = 0; i < 50; i++) {
    if (!this->songs[i].getName()) {
      if (strcmp(this->songs[i].getName(), name) == 0) {
        return this->songs[i];
      } else {
        i++;
      }
    } else {
      break;
    }
  }
  return Song();
}

std::array<Song, 20> Playlist::getSongs() {
  return this->songs;
}