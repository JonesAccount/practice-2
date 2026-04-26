#include <stdio.h>

#define N "\n"
#define T "\t"

int player_attempts = 10;

const char HANGMAN[11][80] = {
    " " N "|/   |" N "|   (_) " N "|   /|\\" N "|    |" N "|   | |" N "|" N "|___ ",
    " " N "|/   |" N "|   (_) " N "|   \\|/" N "|    |" N "|   / \\" N "|" N "|___",
    " " N "|/   |" N "|   (_) " N "|   \\|/" N "|    |" N "|   /" N "|" N "|___   ",
    " " N "|/   |" N "|   (_) " N "|   \\|/" N "|    |" N "|" N "|" N "|___       ",
    " " N "|/   |" N "|   (_) " N "|   \\|" N "|    |" N "|" N "|" N "|___        ",
    " " N "|/   |" N "|   (_) " N "|    |" N "|    |" N "|" N "|" N "|___         ",
    " " N "|/   |" N "|   (_) " N "|" N "|" N "|" N "|" N "|___                   ",
    " " N "|/   |" N "|   (" N "|" N "|" N "|" N "|" N "|___                      ",
    " " N "|/   |" N "|" N "|" N "|" N "|" N "|" N "|___                          ",
    " " N "|/" N "|" N "|" N "|" N "|" N "|" N "|___                              ",
    "|" N "|" N "|" N "|___                                                       "
};

void clear_screen(void) {
    fputs("\033[2J\033[H", stdout);
    fflush(stdout);
}

int main(void) {
    printf("\033[?25l");
    while (1) {
        if (player_attempts < 0) { player_attempts = 10; }
        
        //-----------------------------------------
        if (player_attempts <= 9) { printf(N N N N N N N N T T "   "); }
        
        switch (player_attempts) {
            case 10: printf(N N N N N N N N T T "   |___"); break;
            default: printf("   %s", HANGMAN[player_attempts]);
        }

         //-----------------------------------------
        
        printf(N N N "Lifes: %d", player_attempts + 1);
        (void)getchar();
        clear_screen();
        player_attempts--;
    }
    
    
    return 0;
}