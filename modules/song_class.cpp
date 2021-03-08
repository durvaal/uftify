#include <string>
#include "./headers/song_class.h"

void Song::setName(char name[50]) {
  strncpy(this->name, name, 50);
}

char* Song::getName() {
  return this->name;
}

void Song::setSinger(char singer[50]) {
  strncpy(this->singer, singer, 50);
}

char* Song::getSinger() {
  return this->singer;
}