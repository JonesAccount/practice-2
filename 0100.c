#include <stdio.h>

void iterez(short num, short limit) {
    printf("- %hd\n", num);
    
    if (num > 0)
        iterez(num - 1, limit);
    if (num < limit + 1)
        if (num != 0)
            printf("+ %hd\n", num);
}


int main(void) {
    iterez(9, 9);
    return 0;
}