#include <stdio.h>
#include "./modules/headers/methods.h"

// Starts the initial program instructions
void initializeProgram() {
  int opt, c;

  do {
    printf("\n*===========♫♫♫=============*\n");
    printf("|          UFtify           |\n");
    printf("*===========♫♫♫=============*\n");
    printf("*===========================*\n");
    printf("| 1. Add song               |\n");
    printf("| 2. Search song            |\n");
    printf("| 3. List song              |\n");
    printf("| 4. Clear all songs        |\n");
    printf("| 5. Exit                   |\n");
    printf("*===========================*\n");
    printf("\nType your choice: ");
    
    scanf("%d", &opt);

    while ((c = getchar()) != '\n' && c != EOF) {} // Clear buffer
    
    switch (opt) {
      case 1:
        addSong();
        break;
      case 2:
        searchSong();
        break;
      case 3:
        showSongs();
        break;
      case 4:
        clearSongs();
        break;
      case 5:
        printf("\nSee you later, bye! \n");
        break;
      default:
        printf("\nInvalid choice!\n");
        break;
    }
  }
  
  while (opt != 5);
}

int main() {
    initializeProgram();
    return 0;
}