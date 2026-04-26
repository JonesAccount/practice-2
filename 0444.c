#include <stdio.h>

#define N "\n"
#define T "\t"

int player_attempts = 11;

const char hangman[12][80] = {
    N " ____" N "|/   |" N "|   (_) " N "|   /|\\" N "|    |" N "|   | |" N "|" N "|____ ",
    N " ____" N "|/   |" N "|   (_) " N "|   \\|/" N "|    |" N "|   / \\" N "|" N "|____",
    N " ____" N "|/   |" N "|   (_) " N "|   \\|/" N "|    |" N "|   /" N "|" N "|____   ",
    N " ____" N "|/   |" N "|   (_) " N "|   \\|/" N "|    |" N "|" N "|" N "|____       ",
    N " ____" N "|/   |" N "|   (_) " N "|   \\|" N "|    |" N "|" N "|" N "|____        ",
    N " ____" N "|/   |" N "|   (_) " N "|    |" N "|    |" N "|" N "|" N "|____         ",
    N " ____" N "|/   |" N "|   (_) " N "|" N "|" N "|" N "|" N "|____                   ",
    N " ____" N "|/   |" N "|   (" N "|" N "|" N "|" N "|" N "|____                      ",
    N T " ____" N T "|/   |" N T "|" N T "|" N T "|" N T "|" N T "|" N T "|____                          ",
    N T " _" N T "|/" N T "|" N T "|" N T "|" N T "|" N T "|" N T "|____                              ",
    N N N N N T "|" N T "|" N T "|" N T "|____                                               ",
    N N N N N N N N T "|____                                                           "
};

void clear_screen(void) {
    fputs("\033[2J\033[H", stdout);
    fflush(stdout);
}

int main(void) {
    printf("\033[?25l");
    while (1) {
        if (player_attempts < 0) { player_attempts = 11; }
        
        //-----------------------------------------
        printf("%s", hangman[player_attempts]);
        //-----------------------------------------
        
        printf("\033[15;1Hlifes: %d", player_attempts);
        (void)getchar();
        clear_screen();
        player_attempts--;
    }
    
    
    return 0;
}

/*
 ____
|/   |
|   (_)
|   /|\
|    |
|   | |
|
|_
*/