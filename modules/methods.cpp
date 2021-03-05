#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./headers/song_class.h"
#include "./headers/playlist_class.h"
#include "./headers/methods.h"

class Playlist *startPlaylist;
class Playlist *endPlaylist;
class Playlist *auxiliaryPlaylist;

void addSong() {
  int c;
  char playListName[50];
  char songName[50];
  char songSinger[50];

  Playlist *newPlaylist = (struct Playlist * ) malloc(sizeof(class Playlist));

  printf("\nWhat is the playlist? ");
  fgets(playListName, 50, stdin);

  printf("\nWhat is the song singer? ");
  fgets(songSinger, 50, stdin);
  
  printf("\nWhat is the song name? ");
  scanf("%s", songName);

  while ((c = getchar()) != '\n' && c != EOF) {} // Clear keyboard buffer

  newPlaylist->song.setName(songName);
  newPlaylist->song.setSinger(songSinger);
  newPlaylist->setName(playListName);
  newPlaylist->node = NULL;

  // The list is empty and will insert the first element
  if (startPlaylist == NULL) { 
    startPlaylist = endPlaylist = newPlaylist;
  } else {
    endPlaylist->node = newPlaylist;
    endPlaylist = newPlaylist;
  }
  
  printf("\nSong inserted successfully! \n");
}

void clearSongs() {
  char ch;
  
  if (startPlaylist == NULL) {
    printf("\nThe list is empty!\n");
  } else {
    printf("\nAre you sure you want to empty the entire list? (y/n): ");
    ch = getchar();
    
    if (ch == 'y' || ch == 'Y') {
      while (startPlaylist != NULL) {
        auxiliaryPlaylist = startPlaylist;
        startPlaylist = startPlaylist->node;
        free(auxiliaryPlaylist);
      }
      printf("\nThe list has been successfully emptied!\n");
    } else {
      printf("\nThe list has not been emptied!\n");
    }
  }
}

// Lists all the songs running through the nodes
void showSongs() {
  auxiliaryPlaylist = startPlaylist;
  
  if (startPlaylist == NULL) {
    printf("\nThe list is empty!\n");
  } else {
    printf("\nSongs ♫♫♫\n\n");
    while (auxiliaryPlaylist != NULL) {
      printf("\nPlaylist: %s", auxiliaryPlaylist->getName());
      printf("\nSong: %s", auxiliaryPlaylist->song.getName());
      printf("\nSinger: %s", auxiliaryPlaylist->song.getSinger());
      printf("\n");
      
      auxiliaryPlaylist = auxiliaryPlaylist->node;
    }
  }
}

// Search all the songs running through the nodes
void searchSong() {
  auxiliaryPlaylist = startPlaylist;
  if (auxiliaryPlaylist == NULL) {
    printf("\nThe list is empty!\n");
  } else {
    char name[50];
    printf("\nEnter the song name you are looking for: ");
    scanf("%s", name);
    
    while (auxiliaryPlaylist != NULL) {
      if (strcmp(name, auxiliaryPlaylist->song.getName()) != 0) {
        printf("\nFound %s song!", auxiliaryPlaylist->song.getName());
        printf("\nPlaylist: %s", auxiliaryPlaylist->getName());
        printf("\nSong : %s", auxiliaryPlaylist->song.getName());
        printf("\nSinger: %s", auxiliaryPlaylist->song.getSinger());
        return;
      } else {
        auxiliaryPlaylist = auxiliaryPlaylist->node;
      }
    }
    
    if (auxiliaryPlaylist == NULL) {
      printf("\nSong %s not found!\n", name);
    }
  }
}