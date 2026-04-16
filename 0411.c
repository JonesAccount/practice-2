#include <stdlib.h>
#include <stdio.h>

int main(void) {
    char words[5][10] = {"Query", "Major", "Planet", "Clop", "Rent"};
    
    words[1][0] = 'P';
    words[3][1] = 'w';
    
    for (int i = 0; i < 5; i++) {
        printf("%s ", words[i]);
    }
    
    return 0;
}