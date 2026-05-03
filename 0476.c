#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <termios.h>
#include <unistd.h>

#define TAB "\t"
#define NLINE "\n"
#define BOLD "\033[1m"
#define RESET "\033[0m"

void clear_screen(void) {
    fputs("\033[2J\033[H", stdout);
    fflush(stdout);
}

char getch(void) {
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

const char *title[] = {
 "                                      88                            ",
 "                                      88                            ",
 "                                      88                            ",
 " __  ,adPPYba, 8b,dPPYba,  ,adPPYYba, 88   ,d8  ,adPPYba,           ",
 "{OO} I8[      "" 88P'   \"8a ""       Y8 88 ,a8\"  a8P_88     ",
 "\\__/  \"Y8ba,  88       88 ,adPPPPP88 8888[    8PP""""""\"        ",
 " |^| aa    ]8I 88       88 88,    ,88 88\"Yba, \"8b,   ,aa         ",
 " |^| \"YbbdP\"' 88       88 \"8bbdP\"Y8 88   Y8a \"Ybbd8\"'  /\\",
 " | |______________/ /       ",
 " \\_____________/       "
 };
char *options[] = {" PLAY", "RECORD", "OPTION", " EXIT"};

typedef struct { unsigned int x:2; } St;
St st = {0};

int input_menu(void) {
 char ch = tolower(getch());

 switch (ch) {
  case 'w': st.x--; break;
  case 's': st.x++; break;
  case 10:
  case 13:
   switch (st.x) {
    case 0: return 1;
    case 3:
     clear_screen();
     exit(0);
   }
 }

 return 0;
}

void print_menu_title(void) {
 clear_screen();
 for (int i = 0; i < 10; i++) {
  if (!i) { printf(NLINE NLINE); }
  printf(TAB TAB "%s" NLINE, *(title + i));
 }
}

void print_menu_text(void) {
 printf(BOLD "\033[16;37H%s", (st.x == 0) ? "➤ " : "");
 printf("\033[16;40H%s" RESET, *options);

 printf(BOLD "\033[18;37H%s", (st.x == 1) ? "➤ " : "");
 printf("\033[18;40H%s" RESET, *(options + 1));

 printf(BOLD "\033[20;37H%s", (st.x == 2) ? "➤ " : "");
 printf("\033[20;40H%s" RESET, *(options + 2));

 printf(BOLD "\033[22;37H%s", (st.x == 3) ? "➤ " : "");
 printf("\033[22;40H%s" RESET, *(options + 3));

 fflush(stdout);
}

int main() {
    print_menu_title();
    print_menu_text();
    int a = input_menu();
    return 0;
}