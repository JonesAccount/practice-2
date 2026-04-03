#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

short mistakes = 0;

void render() {
    printf("\n\t  \033[1mВИСЕЛИЦА\033[0m");
    
    if (mistakes == 0) {
        printf("\n\n\t    +---+");
        printf("\n\t    |   |");
        printf("\n\t        |");
        printf("\n\t        |");
        printf("\n\t        |");
        printf("\n\t        |");
        printf("\n\t  ========");
    }
    
    if (mistakes == 1) {
        printf("\n\n\t    +---+");
        printf("\n\t    |   |");
        printf("\n\t    0   |");
        printf("\n\t        |");
        printf("\n\t        |");
        printf("\n\t        |");
        printf("\n\t  ========");
    }
    
    if (mistakes == 2) {
        printf("\n\n\t    +---+");
        printf("\n\t    |   |");
        printf("\n\t    0   |");
        printf("\n\t    |   |");
        printf("\n\t        |");
        printf("\n\t        |");
        printf("\n\t  ========");
    }
    
    if (mistakes == 3) {
        printf("\n\n\t    +---+");
        printf("\n\t    |   |");
        printf("\n\t    0   |");
        printf("\n\t   /|   |");
        printf("\n\t        |");
        printf("\n\t        |");
        printf("\n\t  ========");
    }
    
    if (mistakes == 4) {
        printf("\n\n\t    +---+");
        printf("\n\t    |   |");
        printf("\n\t    0   |");
        printf("\n\t   /|\\  |");
        printf("\n\t        |");
        printf("\n\t        |");
        printf("\n\t  ========");
    }
    
    if (mistakes == 5) {
        printf("\n\n\t    +---+");
        printf("\n\t    |   |");
        printf("\n\t    0   |");
        printf("\n\t   /|\\  |");
        printf("\n\t   /    |");
        printf("\n\t        |");
        printf("\n\t  ========");
    }
    
    if (mistakes == 6) {
        printf("\n\n\t    +---+");
        printf("\n\t    |   |");
        printf("\n\t    0   |");
        printf("\n\t   /|\\  |");
        printf("\n\t   / \\  |");
        printf("\n\t        |");
        printf("\n\t  ========");
    }
    
}

int main(void) {
    printf("\033[?25l");
    fflush(stdout);
    
    for (int i = 0; i < 6; i++) {
        render();
        sleep(1);
        system("clear");
        printf("\033[2J\033[H");
        mistakes = i + 1;
    }
    
    render();
    
    return 0;
}

/*
 
Этап 0 (начало):     Этап 1:              Этап 2:
                                          
  +---+               +---+               +---+
  |   |               |   |               |   |
      |               O   |               O   |
      |                   |               |   |
      |                   |                   |
      |                   |                   |
=========           =========           =========


Этап 3:              Этап 4:              Этап 5:

  +---+               +---+               +---+
  |   |               |   |               |   |
  O   |               O   |               O   |
 /|   |              /|\  |              /|\  |
      |                   |              /    |
      |                   |                   |
=========           =========           =========


Этап 6 (проигрыш):

  +---+
  |   |
  O   |
 /|\  |
 / \  |
      |
=========

*/