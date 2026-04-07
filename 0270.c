#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    int *arr = (int *)calloc(0, sizeof(int));
    
    if (NULL == arr) {
        return 1;
    }
    
    int counter = 1;
    while (1) {
        int temp_num = 0;
        
        int *tmp = realloc(arr, counter * sizeof(int));
        
        if (NULL == tmp) {
            free(arr);
            return 1;
        }
        
        printf("%d. Ввод числа: ", counter);
        if ((scanf("%d", &temp_num)) == 1) {
            short flag = 0;
            for (int i = 0; i < counter; i++) {
                if (temp_num == arr[i]) {
                    flag = 1;
                }
            }
            
            if (flag == 0) {
                arr[counter - 1] = temp_num;
                counter++;
            }
            
        } else {
            int c; while ((c = getchar()) != '\n' && c != EOF) { }
            break;
        }
        
    }
    
    for (int i = 0; i < 0; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}