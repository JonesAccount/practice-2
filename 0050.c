#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    
    char brk[] = "\n\n";
    char spa[] = "      ";
    short int t, s = 0;
    printf("%s%s%sТаймер: ", brk, brk, spa);
    scanf("%hd", &t);
    system("clear");
    
    while (s < t) {
        s++;
        printf("%s%s%sВРЕМЯ: %hi", brk, brk, spa, s);
        fflush(stdout);
        sleep(1);
        system("clear");
    }
    
    
}