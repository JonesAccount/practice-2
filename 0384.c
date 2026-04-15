#include <stdlib.h>
#include <stdio.h>

void revers(int *pa, int *pb) {
    int c = 0; int *pc = &c;
    
    *pc = *pa;
    *pa = *pb;
    *pb = *pc;
}

int main(void) {
    int a = 0, b = 0;
    int *pa = &a, *pb = &b;
    
    printf("Первое число: ");
    scanf("%d", pa);
    
    printf("Второе число: ");
    scanf("%d", pb);
    
    system("clear");
    printf("a: %d b: %d\n", *pa, *pb);
    
    revers(pa, pb);
    printf("\na: %d b: %d", *pa, *pb);
    
    return 0;
}