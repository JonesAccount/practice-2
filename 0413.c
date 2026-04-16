#include <stdlib.h>
#include <stdio.h>

void remember(int *x) {
    static int arr[8] = {0};
    int *p = arr;
    
    if (*(p + 7) != 0) { return; }
    
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++) {
        if (*(p + i) == 0) {
            *(p + i) = *x;
            break;
        }
    }
    
    printf("\n");
    for (int i = 0; i < size; i++) {
        if (*(p + i) == 0) { break; }
        printf("%d ", *(p + i));
    }
    printf("\n\n");
       
}

int main(void) {
    int num = 0;
    int *p = &num;
    
    void (*p_r)(int *);
    p_r = remember;
    while (1) {
        printf("Число (0-нельзя): ");
        scanf("%d", p);
        
        if (*p == 0) { break; }
        
        p_r(p);
    }
    
    system("clear");
    printf("Я предупреждал, 0 нельзя!");
    
    return 0;
}