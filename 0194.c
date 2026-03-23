#include <stdio.h>

int main(void) {
    FILE *f = fopen("text.txt", "w");
    if (f == NULL) { perror("Man!"); return 1; }
    
    fprintf(f, "Hello, C%c", '!');
    fputs("\nHe, Worlds!", f);
    fputc('C', f);
    
    fclose(f);
    
    f = fopen("text.txt", "r");
    if (f == NULL) {perror("Man!!"); return 1;}
    
    char line[300];
    
    while (fgets(line, sizeof(line), f) != NULL) {
        printf("%s", line);
    }
    
    fclose(f);
    
    return 0;
}