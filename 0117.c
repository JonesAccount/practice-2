#include <stdio.h>

int main(void) {
    char w[] = "дом", v[10];
    printf("Пиши: ");
    scanf("%s", v);
    
    int res = strcmp(w, v);
    if (res == 0)
        printf("Одинаково");
    else
        printf("Разные");
}