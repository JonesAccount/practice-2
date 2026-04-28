#include <stdio.h>

#define N "\n"
#define RESET "\033[0m"

#define for(x) for (int i = 1; i <= x; i++) { printf("%d\n", i); }
#define func(y) void func(int y) { printf("\033[3%dmMACROS" RESET, y); }

func(4);

int main(void) {
    printf("\033[?25l");
    
    for(5);
    printf(N);
    for(3);
    
    printf(N);
    
    return 0;
}