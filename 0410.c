#include <stdlib.h>
#include <stdio.h>

int main(void) {
    char *arr[] = {"white", "cat", "Born"};
    for (int i = 0; i < 3; i++) {
        printf("%s ", *(arr + i));
    }
    
    printf("\n\n");
    
    char words[5][10] = {"Query", "Major", "Planet", "Clop", "Rent"};
    
    for (int i = 0; i < 5; i++) {
        printf("%s ", words[i]);
    }
    
    return 0;
}