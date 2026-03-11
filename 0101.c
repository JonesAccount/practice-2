#include <stdio.h>
#include <stdbool.h>


void load(void);


int main(void) {
    load();
    return 0;
}

// переменные
const char R = '>', L = '<';
short counter = 9;
bool selector = true; // false – переключатель назад

// рекурсивная функция
void load(void) {
    printf("%c", (selector == true) ? R : L);
    
    if (counter > 0)
        load(counter - 1);
    if (counter < 9)
        printf("%c", (selector == true) ? R : L);
    
}