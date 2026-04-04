#include <locale.h>
#include <stdio.h>

void main(void) {
    char *locale = setlocale(LC_ALL, "");
    int c = 0b1011;
    //printf("%d\n\n", c);
    
    char letter = 'D';
    //printf("%zu", sizeof(letter));
    
    char text[] = {"C is good program language!"};
    printf("%d битов\n", (strlen(text) + 1) * 8);
    printf("%zu битов", sizeof(text) * 8);
    
    
    char t[] = {"hello"};
    printf("\n\nМассив: %s | %zu бита", t, sizeof(t) * 8);
    
    short l1 = 104, l2 = 101, l3 = 108, l4 = 111;
    printf("\n\nПеременные: %c%c%c%c%c | %zu бита", l1, l2, l3, l3, l4, (sizeof(l1) + sizeof(l2) + sizeof(l3) * 2 + sizeof(l4)) * 8);
    
}