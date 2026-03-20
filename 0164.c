#include <stdio.h>
#include <iso646.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    char text[100];
    printf(">>> ");
    fgets(text, 100, stdin);
    short counter = 0;
    for (int i = 0; i < strlen(text); i++)
        if (text[i] == ' ') counter++;
    printf("%hd", counter + 1);
    return 0;
}