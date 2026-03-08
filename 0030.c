#include <stdio.h>

int main(void)
{
    char q, w, e;
    
    printf("- "); scanf(" %c", &q);
    printf("- "); scanf(" %c", &w);
    printf("- "); scanf(" %c", &e);
    
    printf("%c | %c | %c", e, w, q);
}