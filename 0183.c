#include <stdio.h>

struct House {
    char *material;
    short *rooms;
    int *size;
};

int main(void) {
    printf("\033[?25l");
    
    struct House h1;
    h1.material = "кирпич";
    
    printf("%s", h1.material);
    
    
    return 0;
}