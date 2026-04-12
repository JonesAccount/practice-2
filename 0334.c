#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    printf("\033[?25l");
    fflush(stdout);
    
    int a = 1;
    int *p = &a;
    printf("%d\n", (*p));
    
    p++;
    printf("%d\n", (*p));
    
    p--;
    printf("%d\n", (*p));
    
    p += 5; // 20 bytes
    printf("%d\n", (*p));
    
    p -= 4; p--;
    printf("%d\n\n", (*p));
    
    char b = 'A';
    char *pB = &b;
    char res;
    for (int i = 1; i <= 100; i++) {
        res = *(pB + i);
        printf("%c | %d\n", res, res);
        sleep(1);
    }
    
    return 0;
}