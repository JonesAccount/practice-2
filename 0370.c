#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void render_territory(char territory[2][3]);

int main(void) {
    printf("\033[?25l");
    srand(time(NULL));
    
    char territory[2][3];

    int plot = 1;
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            territory[i][j] = '0' + plot;
            plot++;
        }
    }
    
    bool running = true;
    while (running) {
        
        render_territory(territory);
        
        (void)getchar();
    }
    
    return 0;
}

void render_territory(char territory[2][3]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("\033[30;42m%c\033[0m", territory[i][j]);
        }
        printf("\n");
    }
    
}