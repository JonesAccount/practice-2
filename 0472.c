#include <stdlib.h>
#include <stdio.h>

typedef struct {
    unsigned int x:3;
    unsigned int y:5;
    unsigned int z:2;
} S;

int main(void) {
    printf("\033[?25l");
  
    while (1) {
        static S s = {0, 0, 0};
        printf("x:%u y:%u z:%u", s.x, s.y, s.z);
        
        s.x++;
        s.y++;
        s.z++;
        
        system("clear");
        (void)getchar();
    }
    
    return 0;
}