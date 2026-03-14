#include <stdio.h>

#define HEIGHT 5
#define WIDTH 11

int main(void) {
    char input;
    
    char map[HEIGHT][WIDTH] = {
        "##########",
        "#        #",
        "#    @   #",
        "#        #",
        "##########"
    };
    printf("%s", map[0]);
    printf("\tДвижение: WASD\n");
    
    for (short i = 1; i < 5; i++)
        printf("%s\n", map[i]);
    
    printf("\n>>> ");
    scanf("%c", &input);
    
    return 0;
}