#include <stdlib.h>
#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    int *arr = (int *)calloc(1, sizeof(int));
    if (NULL == arr) { return 1; }
    
    arr[0] = 1;
    
    int *p = arr;
    
    printf("1 — %p\n", (void *)p);
    for (size_t index = 1;; index++) {
        int *temp = realloc(p, (index + 1) * sizeof(int));
        if (NULL == temp) { return 1; }
        
        *p = *temp;
        p[index] = 1;
        
        printf("%d — %p\n", index + 1, (void *)p);
        
        (void)getchar();
    }
    
    return 0;
}