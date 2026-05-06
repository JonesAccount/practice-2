#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *dictionary;

int main(void) {
	printf("\033[?25l");

	dictionary = malloc(500);

	char words[5][8] = {"Tall", "App", "Vulcan", "Similar", "Exercise"};

	for (int i = 0; i < 5; i++) {
		*(dictionary + i) = '\n';
		i++;
		*(dictionary + i) = '-';
		i++;
		*(dictionary + i) = ' ';
		i++;

		for (int j = 0; j < strlen(words[i]); j++) {
			*(dictionary + i) = words[i][j];
			i++;
		}

	}

	while (1) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < strlen(words[i]); j++) {
				printf("%c", words[i][j]);
			}
			printf("\n");
		}

		getchar();
	}

	return 0;
}
