#include <stdlib.h>
#include <stdio.h>

int main(void) {
    char *names[3];
    for (int i = 0; i < 3; i++) {
        *(names + i) = malloc(11);
        printf("Имя %d: ", i + 1);
        scanf("%10s", names + i);
    }
    
    printf("\n\n");
    for (int i = 0; i < 3; i++) {
        printf("%s ", *names);
        names++;
    }
    
    return 0;
}