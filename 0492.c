#include <stdio.h>
#include <string.h>

int main(void) {
    char w1[] = "TUF ";
    char w2[] = "GAMING";
    
    strcat(w1, w2);
    
    printf("%s", w1);
    
    return 0;
}