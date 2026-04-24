#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef void (p)(void);

void f1(void) { printf("Yes\n"); }
void f2(void) { printf("No\n"); }

int main(void) {
    fflush(stdout);
    
    p *p1 = &f1;
    p *p2 = &f2;
    
    int X = 1;
    while (1) {
        if (X) { p1(); X = 0; }
        else if (!X) { p2(); X = 1; }
        sleep(1);
        system("clear");
    }
    
    return 0;
}