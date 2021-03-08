#ifndef __METHODS_H_
#define __METHODS_H_

void findPlayListByName(char playListName[50]);
void addElement(bool multipleSongs, Playlist *playlistFinded);
void addElement(Playlist &playlistFinded);
void addElement(Playlist &playlistFinded, char playListName[50]);
void clearSongs();
void showSongs();
void searchSong();
void initializeProgram();

#endif