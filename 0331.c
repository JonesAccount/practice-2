#include <stdlib.h>
#include <stdio.h>

typedef long double Ld16;

void MemAvailable(void) {
    FILE* f = fopen("/proc/meminfo", "r");
    char line[256];

    while (fgets(line, sizeof(line), f)) {
        if (strncmp(line, "MemAvailable", 12) == 0) {
            printf("%s", line);
            break;
        }
    }

    fclose(f);
}

int main() {
    printf("\033[?25l");
    Ld16 *p = (Ld16 *)malloc(0);
    
    for (size_t index = 0;; index++) {
        Ld16 *tmp = realloc(p, (index + 1) * sizeof(Ld16));
        p = tmp;
        p[index] = 1.189731495357231765e+4932L;
        MemAvailable();
        printf("%zu:%p", index + 1, (void *)&p[index]);
        printf("\n- - - - - - - - - - - - - - -\n");
    }
    
    return 0;
}