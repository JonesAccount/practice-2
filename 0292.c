#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {
    printf("\033[?25l");
    
    const char *arr[] = {"hi", "c", "good", "day"};
    
    printf("%s %s! %s %s :)", arr[1], arr[0], arr[2], arr[3]);
    
    return 0;
}