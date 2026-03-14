#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int start, finish, step;
    printf("start finish step: ");
    scanf("%d%d%d", &start, &finish, &step);
    
    while ((step > 0) ? start < finish : start > finish) {
        if (step == 0) {
            printf("Динаху");
            exit(0);
        }
        printf("x = %d\n", start);
        start += step;
    }
    
    printf("After: %d", start);
}