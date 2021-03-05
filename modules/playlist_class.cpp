#include <string.h>
#include "./headers/playlist_class.h"

void Playlist::setName(char name[50]) {
  strcpy(this->name, name);
}

char* Playlist::getName() {
  return this->name;
}