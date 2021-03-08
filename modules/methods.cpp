#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./headers/song_class.h"
#include "./headers/playlist_class.h"
#include "./headers/methods.h"

Playlist *startPlaylist;
Playlist *endPlaylist;
Playlist *auxiliaryPlaylist;

void findPlayListByName(char playListName[50], Playlist *playlistFinded) {
  if (!auxiliaryPlaylist->getName()) {
    printf("\nThe list of playlist is empty!\n");
  } else {
    while (auxiliaryPlaylist->getName()) {
      if (strcmp(playListName, auxiliaryPlaylist->getName()) == 0) {
        playlistFinded = auxiliaryPlaylist;
      }
    }
    
    if (!playlistFinded->getName()) {
      printf("\nPlaylist %s not found!\n", playListName);
    }
  }
}

void addElement(bool multipleSongs) {
  int c;
  char playListName[50];

  printf("\nWhat is the playlist? ");
  scanf("%s", playListName);

  while ((c = getchar()) != '\n' && c != EOF) {} // Clear keyboard buffer

  Playlist *playlistFinded;
  findPlayListByName(playListName, playlistFinded);
  
  if (multipleSongs == false) {
    addElement(playlistFinded);
  } else {
    addElement(playlistFinded, playListName);
  }
}

void addElement(Playlist playlistFinded) {
  int c;
  char songName[50];
  char songSinger[50];

  printf("\nWhat is the song singer? ");
  fgets(songSinger, 50, stdin);
  
  printf("\nWhat is the song name? ");
  scanf("%s", songName);

  while ((c = getchar()) != '\n' && c != EOF) {} // Clear keyboard buffer
  
  Song song;
  song.setName(songName);
  song.setSinger(songSinger);
  
  playlistFinded.setSong(song);
  
  printf("\nSong inserted successfully! \n");
}

void addElement(Playlist *playlistFinded, char playListName[50]) {
  Playlist *newPlaylist;

  newPlaylist->setName(playListName);
  newPlaylist->node = NULL;

  for (int i = 0; i < 50; i++) {
    if (playlistFinded.getSongs[i].getName()) {
      break;
    } else {
      i++;
      newPlaylist->setSong(playlistFinded.getSongs[i]);
    }
  }

  // The list is empty and will insert the first element
  if (!startPlaylist->getName()) { 
    startPlaylist = endPlaylist = newPlaylist;
  } else {
    endPlaylist->node = newPlaylist;
    endPlaylist = newPlaylist;
  }
  
  printf("\nPlayList inserted successfully! \n");
}

void clearSongs() {
  char ch;
  
  if (!startPlaylist->getName()) {
    printf("\nThe list is empty!\n");
  } else {
    printf("\nAre you sure you want to empty the entire list? (y/n): ");
    ch = getchar();
    
    if (ch == 'y' || ch == 'Y') {
      while (startPlaylist->getName()) {
        auxiliaryPlaylist = startPlaylist;
        startPlaylist = startPlaylist->node;
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
  
  if (!startPlaylist->getName()) {
    printf("\nThe list is empty!\n");
  } else {
    printf("\nSongs ♫♫♫\n\n");
    while (auxiliaryPlaylist->getName()) {
      printf("\nPlaylist: %s", auxiliaryPlaylist.getName());
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
  if (!auxiliaryPlaylist->getName()) {
    printf("\nThe list is empty!\n");
  } else {
    char name[50];
    printf("\nEnter the song name you are looking for: ");
    scanf("%s", name);
    
    while (auxiliaryPlaylist->getName()) {
      if (strcmp(name, auxiliaryPlaylist->song.getName()) == 0) {
        printf("\nFound %s song!", auxiliaryPlaylist->song.getName());
        printf("\nPlaylist: %s", auxiliaryPlaylist->getName());
        printf("\nSong : %s", auxiliaryPlaylist->song.getName());
        printf("\nSinger: %s", auxiliaryPlaylist->song.getSinger());
        return;
      } else {
        auxiliaryPlaylist = auxiliaryPlaylist->node;
      }
    }
    
    if (!auxiliaryPlaylist->getName()) {
      printf("\nSong %s not found!\n", name);
    }
  }
}

// Starts the initial program instructions
void initializeProgram() {
  int opt, c;

  do {
    printf("\n*===========♫♫♫=============*\n");
    printf("|          UFtify           |\n");
    printf("*===========♫♫♫=============*\n");
    printf("*===========================*\n");
    printf("| 1. Add new playlist       |\n");
    printf("| 2. Add new song           |\n");
    printf("| 3. Search song            |\n");
    printf("| 4. List song              |\n");
    printf("| 5. Clear all songs        |\n");
    printf("| 6. Exit                   |\n");
    printf("*===========================*\n");
    printf("\nType your choice: ");
    
    scanf("%d", &opt);

    while ((c = getchar()) != '\n' && c != EOF) {} // Clear buffer
    
    switch (opt) {
      case 1:
        addElement(true);
        break;
      case 2:
        addElement(false);
        break;
      case 3:
        searchSong();
        break;
      case 4:
        showSongs();
        break;
      case 5:
        clearSongs();
        break;
      case 6:
        printf("\nSee you later, bye! \n");
        break;
      default:
        printf("\nInvalid choice!\n");
        break;
    }
  }
  
  while (opt != 6);
}