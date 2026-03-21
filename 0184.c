#include <stdio.h>
#include <stdlib.h>

struct Player {
    char *nick;
    char *male;
    int *age;
    float *exper;
};

int main(void) {
    struct Player one;
    printf("\033[?25l");
    
    printf("\033[33mСОЗДАНИЕ ПЕРСОНАЖА\033[0m\n\n");
    
    one.nick = malloc(100 * sizeof(char));
    one.male = malloc(10 * sizeof(char));
    one.age = malloc(sizeof(int));
    one.exper = malloc(sizeof(float));
    
    printf("1. Ник: ");
    fgets(one.nick, 100, stdin);
    one.nick[strcspn(one.nick, "\n")] = 0;
    
    printf("2. Пол: ");
    scanf("%s", one.male);
    
    printf("3. Возраст: ");
    scanf("%d", one.age);
    
    printf("4. Опыт: ");
    scanf("%f", one.exper);
    
    system("clear");
    
    printf("\033[33mПЕРСОНАЖ ГОТОВ\033[0m\n\n");
    
    printf("- %s\n", one.nick);
    printf("- %s\n", one.male);
    printf("- %d\n", *one.age);
    printf("- %.1f", *one.exper);
    
    free(one.nick);
    free(one.male);
    free(one.age);
    free(one.exper);
    return 0;
}