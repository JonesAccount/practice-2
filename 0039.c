#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[4];
    printf("Ввод: ");
    scanf(" %3s", str);
    
    if (strcmp(str, "yes") == 0) {
        printf("Ты – гей");
    } else {
        printf("Ты не гей");
    }
    
    return 0;
}