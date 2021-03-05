#ifndef __SONG_CLASS_H_
#define __SONG_CLASS_H_

class Song {
  private:
    char name[50];
    char singer[50];

  public:
    Song();
    ~Song();

    void setName(char name[50]);
    char* getName();
    void setSinger(char singer[50]);
    char* getSinger();
};

#endif