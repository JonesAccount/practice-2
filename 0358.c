#include <stdio.h>

int main(void) {
    int a = 10;
    
    const int *p = &a;
    printf("%d\n", *p);
    
    p = NULL;
    if (NULL == p) {
        printf("NULL");
    } else {
        printf("NOT NULL");
    }
    
    
    return 0;
}