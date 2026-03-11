#include <stdio.h>

int lincen(short num);


int main(void) {
    
    short number;
    short * pNum = &number;
    printf("Единица: ");
    scanf("%hd", pNum);
    int res = lincen(pNum);
    printf("\n\nРезультат:");
    printf("%d", res);
    
    return 0;
}


int lincen(short num) {
    return 50;
}