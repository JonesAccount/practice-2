#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    printf("\033[?25l");

    char *lets = (char *)calloc(0, sizeof(char));

    if (NULL == lets) {
        printf("exit...");
        return 1;
    }

    for (int i = 0; i < 26; i++) {
        char *tmp = realloc(lets, i + 1 * sizeof(char));

        if (NULL == tmp) {
            printf("exit...");
            return 1;
        }

        lets = tmp;

        while (lets[i] == 0) {
            char letter = rand() % (90 - 65 + 1) + 65;
            bool check_letter = true;

            for (int j = 0; j < i + 1; j++) {
                if (letter == lets[j]) {
                    check_letter = false;
                }
            }

            if (check_letter) {
                lets[i] = letter;
            }

        }

    }

    char unsort[26] = {0};
    for (int i = 0; i < 26; i++) {
    	unsort[i] = lets[i];
    }

    short min = lets[0];
    for (int i = 1; i < 26; i++) {
        if (lets[i] < min) {
            min = lets[i];
        }
    }

    char *arr = (char *)malloc(sizeof(char) * 1);

    if (NULL == arr) {
        printf("exit...");
        return 1;
    }

    arr[0] = min;

    for (int i = 1; i < 27; i++) {
        char *tmp = realloc(arr, i + 1 * sizeof(char));

        if (NULL == tmp) {
        	printf("exit...");
            return 1;
        }

		arr = tmp;

		for (int j = 0; j < 26; j++) {
			if (lets[j] - arr[i - 1] == 1) {
				arr[i] = lets[j];
				lets[j] = 91;
				break;
			}
		}

    }

    char sort[26] = {0};
    for (int i = 0; i < 26; i++) {
    	sort[i] = arr[i];
    }

    printf("\n\n");
    for (int i = 0; i < 26; i++) {
        printf("%10d. %c/%c%15d. %c/%c\n", gi + 1, unsort[i], tolower(unsort[i]), i + 1, sort[i], tolower(sort[i]));
    }

    getchar();
    free(lets);
    return 0;
}
