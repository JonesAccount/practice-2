#include <stdlib.h>
#include <stdio.h>

void clear_screen(void) {
    fputs("\033[2J\033[H", stdout);
    fflush(stdout);
}

void foo(int **arr, int x) {
        static int index = 0;

        int *tmp = realloc(*arr, (index + 1) * sizeof(int));
        if (NULL == tmp) { return; }

        *arr = tmp;
        *(*arr + index) = x;

        clear_screen();

        for (int i = 0; i < (index + 1); i++) {
            printf("%d ", *(*arr + i));
        }

        printf("\n\n");
        index++;
}

int main(void) {
        // локальный блок 1
        {
                printf("\033[?25l");
        }

        // локальный блок 2
        {
                int *arr = NULL;
                int number = 0;
                void (*p)(int **, int);
                p = foo;
                for (int i = 1;;i++) {
                        printf("%d | число: ", i);
                        scanf("%d", &number);

                        if (number == 0) { break; }

                        p(&arr, number);
                }

                free(arr);
        }

        // локальный блок 3
        {
                printf("Завершение...");
                printf("\033[?25h");
        }
        return 0;
}