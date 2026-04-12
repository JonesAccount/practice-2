#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    fflush(stdout);
    
    int arr[1000000];
    int *p = arr;
    p[0] = 1;
    
    printf("1 — %p\n", (void *)p);
    for (size_t index = 1;; index++) {
        p[index] = 1;
        printf("%d — %p\n", index + 1, (void *)&p[index]);
        
        usleep(1);
    }
    
    return 0;
}