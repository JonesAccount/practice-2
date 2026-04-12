#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define RAND rand() % (99 - 0 + 1) + 1

int main() {
    printf("\033[?25l");
    srand(time(NULL));
    fflush(stdout);
    
    int arr[100] = {0};
    for(int i = 0; i < 100; i++) {
        arr[i] = i + 1;
    }
     
    int *ps;
    int *pe;
    while (1) {
        ps = &arr[RAND];
        
        while (1) {
            pe = &arr[RAND];
            if (*pe > *ps || *pe == *ps) { break; }
        }
        
        ptrdiff_t r = pe - ps;
        printf("%d - %d = %td\n", *pe, *ps, r);
        
        sleep(1);
    }
    
    return 0;
}