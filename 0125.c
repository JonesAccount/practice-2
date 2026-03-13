#include <stdio.h>
#include <locale.h>

void game(void);

int main(void) {
    setlocale(LC_ALL, "");
    game();
    return 0;
}

void game(void) {
    printf("═══════════════════\n");
    printf("║                     \n");
    printf("║               ┌───┐           \n");
    printf("║               │                \n");
    printf("║               │   O            \n");
    printf("║               │  /|\\          \n");
    printf("║               │  / \\          \n");
    printf("║               │               \n");
    printf("║             ══╧══             \n\n");
    printf("═══════════════════\n");
    
}