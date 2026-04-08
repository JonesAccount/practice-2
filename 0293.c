#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {
    printf("\033[?25l");
    
    const char arr[] = {"fhh"};
    
    printf("%d\n", arr[0]);
    printf("%d\n", arr[1]);
    printf("%d\n", arr[2]);
    printf("%d\n", arr[3]);
    
    return 0;
}