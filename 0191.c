#include <stdio.h>

int main(void) {
    FILE *f = fopen("text.txt", "w");
    fprintf(f, "Записал данные\n");
    fclose(f);
    return 0;
}