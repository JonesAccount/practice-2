#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef long double Ld16;

int main(void) {
    printf("\033[?25l");
    fflush(stdout);
    
    Ld16 *p = (Ld16 *)malloc(0);
    
    for (size_t index = 0;; index++) {
        Ld16 *tmp = realloc(p, (index + 1) * sizeof(Ld16));
        p = tmp;
        p[index] = 1;
        printf("%zu - %p\n", index + 1, (void *)&p[index]);
        
        //usleep(1);
    }
    
    return 0;
}