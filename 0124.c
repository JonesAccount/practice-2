#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {
    setlocale(LC_ALL, "");
    srand(time(NULL));
    char uinput[5];
    short choice_word;
    
    const char *words[] = {
        "Машина",
        "Дом",
        "Самолет",
        "Деньги",
        "Телефон",
        "Земля",
        "Шар",
        "Цирк",
        "Гир"
    };
    
    while (1) {
        choice_word = rand() % 9;
        short word_len = strlen(words[choice_word]) / 2;
        short * pL = &word_len;
        
        printf("Слово: ");
        for (short i = 0; i < *pL; i++) {
            printf("_ ");
        }
    
        printf(" (длина %hd)", *pL);
    
        while (1) {
            printf("\n\n:: ");
            scanf("%1s", uinput);
            for (short i = 0; i < *pL; i++) {
            if (words[i] == uinput)
                printf("Верно");
        }
        }
    }
    
    return 0;
}