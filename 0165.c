#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char fullname[50];
    
    printf("Полное имя: ");
    fgets(fullname, 50, stdin);
    system("clear");
    printf("Привет, %s!", fullname);
    
    return 0;
}