#include <stdbool.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>

#define YELLOW "\033[33m"
#define BOLD "\033[1m"
#define RESET "\033[0m"
#define N "\n"
#define T "\t"

void render_menu(bool);
void handle_menu_input(bool *, bool *, bool *);

void render_game(int, char *, char *, char *, char *, char *, int *, bool *);
void handle_game_input(char *, char *, bool *);
void match_check(char *, char *, char *, int *, bool *);

void clear_screen(void);
char read_char(void);

int main(void) {
    printf("\033[?25l");
    srand(time(NULL));
    
    bool running_menu = true;
    bool running_game = false;
    bool selected_option = true;
    
    bool *menuPtr = &running_menu;
    bool *gamePtr = &running_game;
    bool *selectedPtr = &selected_option;
        
    while (running_menu) {
        render_menu(selected_option);
        handle_menu_input(menuPtr, gamePtr, selectedPtr);
        clear_screen();
    }
    
    int player_attempts = 11;
    int *player_attemptsPtr = &player_attempts;
    
    bool is_space_pressed_or_not = false;
    bool *is_space_pressed_or_notPtr = &is_space_pressed_or_not;
    
    char alphabet[] = {"QWERTYUIOPASDFGHJKLZXCVBNM"};
    char alphabetto_check_selected_letters[26];
    char selected_letter = '0';
    
    
    char *words[] = {"bird", "dord", "buhe"};
    int choice_word = rand() % 3;
    
    char word_guess[strlen(*(words + choice_word))];
    strcpy(word_guess, words[choice_word]);
    char render_guess_lets[strlen(*(words + choice_word))];
    
    for (int i = 0; i < strlen(*(words + choice_word)); i++) {
        render_guess_lets[i] = '_';
    }
    
    
    char *alphabetto_check_selected_lettersPtr = alphabetto_check_selected_letters;
    char *selected_letterPtr = &selected_letter;
    char *render_guess_letsPtr = render_guess_lets;
    
    while (running_game) {
        render_game(player_attempts, word_guess, alphabet, selected_letterPtr, alphabetto_check_selected_lettersPtr, render_guess_letsPtr, player_attemptsPtr, is_space_pressed_or_notPtr);
        handle_game_input(selected_letterPtr, alphabetto_check_selected_lettersPtr, is_space_pressed_or_notPtr);
        clear_screen();
    }
    
    return 0;
}

void render_menu(bool selected_option) {
    const char *TITLE[] = {
 " _                                     ",
 "| |_  __ _ _ _  __ _ _ __  __ _ _ _   ",
 "| ' \\/ _` | ' \\/ _` | '  \\/ _` | ' \\  ",
 "|_||_\\__,_|_||_\\__, |_||_|\\__,_|_||_| ",
 "                |___/       |         ",
 "                           (_)        ",
 "                           /|\\        ",
 "                            |         ",
 "                           | |        "
 };
        
    for (int i = 0; i < 9; i++) {
        if (!i) { printf("\n    "); }
        printf(BOLD "%s\n    " RESET, *(TITLE + i));
    }
    
    printf("\n\n\t\t%sStart", (selected_option) ? "==> " : "    ");
    printf("\n\n\t\t%sQuit\n\n", (!selected_option) ? "==> " : "    ");
    
    // разделительная линия
    // dividing line
    for (int i = 0; i < 19; i++) {
        if (!i) { printf("\n     "); }
        printf("- ");
    }
    
    printf("\n\n\t [w/s] navigate   [y] confirm");
    
}

void handle_menu_input(bool *menuPtr, bool *gamePtr, bool *selectedPtr) {
    char ch = tolower(read_char());
    
    switch (ch) {
        case 'w': *selectedPtr = true; break;
        case 's': *selectedPtr = false; break;
        case 'y':
            *menuPtr = false;
            if (*selectedPtr) { *gamePtr = true; }
    }
    
}

void render_game(int player_attempts, char *word_guess, char *alphabet, char *selected_letterPtr, char *alphabetto_check_selected_lettersPtr, char *render_guess_letsPtr, int *player_attemptsPtr, bool *is_space_pressed_or_notPtr) {

const char *HANGMAN_10[] = {"|", "|", "|", "|___"};
    const char *HANGMAN_9[] = {" __", "|/", "|", "|", "|", "|", "|", "|___"};
    const char *HANGMAN_8[] = {" __", "|/   |", "|", "|", "|", "|", "|", "|___"};
    const char *HANGMAN_7[] = {" __", "|/   |", "|   (", "|", "|", "|", "|", "|___"};
    const char *HANGMAN_6[] = {" __", "|/   |", "|   (_) ", "|", "|", "|", "|", "|___"};
    const char *HANGMAN_5[] = {" __", "|/   |", "|   (_) ", "|    |", "|    |", "|", "|", "|___"};
    const char *HANGMAN_4[] = {" __", "|/   |", "|   (_) ", "|   \\|", "|    |", "|", "|", "|___"};
    const char *HANGMAN_3[] = {" __", "|/   |", "|   (_) ", "|   \\|/", "|    |", "|", "|", "|___"};
    const char *HANGMAN_2[] = {" __", "|/   |", "|   (_) ", "|   \\|/", "|    |", "|   /", "|", "|___"};
    const char *HANGMAN_1[] = {" __", "|/   |", "|   (_) ", "|   \\|/", "|    |", "|   / \\", "|", "|___"};
    const char *HANGMAN_0[] = {" __", "|/   |", "|   (_) ", "|   /|\\", "|    |", "|   | |", "|", "|___"};
            
    switch (player_attempts) {
        case 11:
            printf(N N N N N N N N T T "   |___");
            break; 
        case 10:
            for (int i = 0; i < 4; i++) {
                if (!i) { printf(N N N N N T T); }
                printf("   %s" N T T, *(HANGMAN_10 + i));
            }
            break; 
        case 9:
            for (int i = 0; i < 8; i++) {
                if (!i) { printf(N T T); }
                printf("   %s" N T T, *(HANGMAN_9 + i));
            }
            break; 
        case 8:
            for (int i = 0; i < 8; i++) {
                if (!i) { printf(N T T); }
                printf("   %s" N T T, *(HANGMAN_8 + i));
            }
            break;
        case 7:
             for (int i = 0; i < 8; i++) {
                if (!i) { printf(N T T); }
                printf("   %s" N T T, *(HANGMAN_7 + i));
            }
            break;
        case 6:
            for (int i = 0; i < 8; i++) {
                if (!i) { printf(N T T); }
                printf("   %s" N T T, *(HANGMAN_6 + i));
            }
            break;
        case 5:
            for (int i = 0; i < 8; i++) {
                if (!i) { printf(N T T); }
                printf("   %s" N T T, *(HANGMAN_5 + i));
            }
            break;
        case 4:
            for (int i = 0; i < 8; i++) {
                if (!i) { printf(N T T); }
                printf("   %s" N T T, *(HANGMAN_4 + i));
            }
            break;
        case 3:
             for (int i = 0; i < 8; i++) {
                if (!i) { printf(N T T); }
                printf("   %s" N T T, *(HANGMAN_3 + i));
            }
            break;
        case 2:
             for (int i = 0; i < 8; i++) {
                if (!i) { printf(N T T); }
                printf("   %s" N T T, *(HANGMAN_2 + i));
            }
            break;
        case 1:
            for (int i = 0; i < 8; i++) {
                if (!i) { printf(N T T); }
                printf("   %s" N T T, *(HANGMAN_1 + i));
            }
            break;
        case 0:
            for (int i = 0; i < 8; i++) {
                if (!i) { printf(N T T); }
                printf("   %s" N T T, *(HANGMAN_0 + i));
            }
            break;
        }
    
        // место для слова
        // place for a word
        match_check(word_guess, selected_letterPtr, render_guess_letsPtr, player_attemptsPtr, is_space_pressed_or_notPtr);
    
        // английски алфавит
        // english alphabet
        for (int i = 0; i < 26; i++) {
            if (!i) { printf(N N T "     "); }
            
            // для проверки буква уже выбрана или нет
            bool check_selected = false;
    
            for (int j = 0; j < 26; j++) {

if (tolower(*(alphabetto_check_selected_lettersPtr + j)) == *(alphabet + i)) { check_selected = true; }
            }
            
            if (!check_selected) {
                printf("%s", (*selected_letterPtr == *(alphabet + i)) ? "\033[33m" : "");
            } else {
                printf("%s", (*selected_letterPtr == *(alphabet + i)) ? "\033[90m" : "");
            }
            
            printf("%c " RESET, *(alphabet + i));
            
            //printf("%s%c " RESET, (*selected_letterPtr == *(alphabet + i)) ? "\033[33m" : "", *(alphabet + i));
            
            if (*(alphabet + i) == 'P') { printf(N T "      "); }
            if (*(alphabet + i) == 'L') { printf(N T "        "); }
            if (i == 90) { printf("\n"); }
        }
    
        // разделительная линия
        // dividing line
        for (int i = 0; i < 19; i++) {
            if (!i) { printf("\n\n     "); }
            printf("- ");
        }
    
        // инструкция
        // instructions
        printf("\n\n\t       [space] confirm");
    
}

void handle_game_input(char *selected_letterPtr, char *alphabetto_check_selected_lettersPtr, bool *is_space_pressed_or_notPtr) {
    char ch = tolower(read_char());
    
    // для проверки буква уже нажата или нет
    bool check_selected = false;
    
    static int index_selected_letters = 0;
    
    switch (ch) {
        case 'q':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'q') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'Q'; }
            break;
        case 'w':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'w') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'W'; }
            break;
        case 'e':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'e') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'E'; }
            break;
        case 'r':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'r') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'R'; }
            break;
        case 't':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 't') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'T'; }
            break;
        case 'y':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'y') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'Y'; }
            break;
        case 'u':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'u') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'U'; }
            break;
        case 'i':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'i') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'I'; }
            break;
        case 'o':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'o') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'O'; }
            break;
        case 'p':

for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'p') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'P'; }
            break;
        case 'a':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'a') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'A'; }
            break;
        case 's':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 's') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'S'; }
            break;
        case 'd':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'd') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'D'; }
            break;
        case 'f':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'f') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'F'; }
            break;
        case 'g':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'g') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'G'; }
            break;
        case 'h':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'h') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'H'; }
            break;
        case 'j':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'j') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'J'; }
            break;
        case 'k':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'k') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'K'; }
            break;
        case 'l':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'l') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'L'; }
            break;
        case 'z':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'z') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'Z'; }
            break;
        case 'x':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'x') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'X'; }
            break;
        case 'c':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'c') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'C'; }
            break;
        case 'v':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'v') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'V'; }
            break;
        case 'b':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'b') { check_selected = true; }

}
            if (!check_selected) { *selected_letterPtr = 'B'; }
            break;
        case 'n':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'n') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'N'; }
            break;
        case 'm':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'm') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'M'; }
            break;
        case ' ':
            *is_space_pressed_or_notPtr = true;
            if (*selected_letterPtr != '0') {
                for (int i = 0; i < 26; i++) {
                    if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == *selected_letterPtr) { check_selected = true; }
                }
                if (!check_selected) {
                    alphabetto_check_selected_lettersPtr[index_selected_letters] = *selected_letterPtr;
                    index_selected_letters++;
                }
            }
    }
    
}

void match_check(char *word_guess, char *selected_letterPtr, char *render_guess_letsPtr, int *player_attemptsPtr, bool *is_space_pressed_or_notPtr) {
    int word_length = strlen(word_guess);
    char indents[10];
    
    switch (word_length) {
        case 3: strcpy(indents, N N N T T "    "); break;
        case 4: strcpy(indents, N N N T T "   "); break;
        case 5: strcpy(indents, N N N T T "  "); break;
        case 6: strcpy(indents, N N N T T " "); break;
    }
    
    for (int i = 0; i < word_length; i++) {
         if (!i) { printf("%s", indents); }
         printf("%c ", *(render_guess_letsPtr + i));
     }
    
    // проверяем есть ли такая буква, если есть, рендерим, иначе минус жизнь
    if (*is_space_pressed_or_notPtr) {
        for (int i = 0; i < word_length; i++) {
            if (*(word_guess + i) == tolower(*selected_letterPtr)) {
                *(render_guess_letsPtr + i) = *selected_letterPtr;
            }
        }
        int flag = true;
        for (int i = 0; i < word_length; i++) {
            if (*(word_guess + i) != tolower(*selected_letterPtr)) {
                flag = false;
            }
        }
    
        if (flag) { (*player_attemptsPtr)--; }
        
        *is_space_pressed_or_notPtr = false;
    }
}

void clear_screen(void) {
    fputs("\033[2J\033[H", stdout);
    fflush(stdout);
}

char read_char(void) {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);       
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);    
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); 
    return ch;
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

/*
 'ant baboon badger bat bear beaver camel cat clam cobra cougar '
         'coyote crow deer dog donkey duck eagle ferret fox frog goat '
         'goose hawk lion lizard llama mole monkey moose mouse mule newt '
         'otter owl panda parrot pigeon python rabbit ram rat raven '
         'rhino salmon seal shark sheep skunk sloth snake spider '
         'stork swan tiger toad trout turkey turtle weasel whale wolf '
         'wombat zebra ').split()
 */
