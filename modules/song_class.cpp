#include <string.h>
#include "./headers/song_class.h"

void Song::setName(char name[50]) {
  strcpy(this->name, name);
}

char* Song::getName() {
  return this->name;
}

void Song::setSinger(char singer[50]) {
  strcpy(this->singer, singer);
}

char* Song::getSinger() {
  return this->singer;
}