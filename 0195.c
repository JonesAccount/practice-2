#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    // ЗАПИСЬ
    FILE *f = fopen("text.txt", "w");
    if (f == NULL) { perror("Man!"); return 1; }
    
    char bufer[100];
    while (1) {
        printf("Запись: ");
        scanf("%s", bufer);
        if (strcmp(bufer, "1") == 0) break;
        else fprintf(f, "%s\n", bufer);
    }
    
    fclose(f);
    // ЧТЕНИЕ
    f = fopen("text.txt", "r");
    if (f == NULL) { perror("Man!!"); return 1; }
    
    char line[300];
    
    system("clear");
    while (fgets(line, sizeof(line), f) != NULL)
        printf("%s", line);
    
    fclose(f);
    
    return 0;
}