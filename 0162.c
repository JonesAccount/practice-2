#include <stdio.h>
#include <iso646.h>

int main(void) {
    char text1[50], text2[50];
    printf("1: ");
    scanf("%s", text1);
    
    printf("2: ");
    scanf("%s", text2);
    
    printf("\n%s", text1);
    printf("\n%s", text2);
    return 0;
}