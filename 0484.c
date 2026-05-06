#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *dictionary;

int main(void) {
	printf("\033[?25l");

	dictionary = malloc(0);

	char line[100];

	int counter = 1;
	while (1) {
		char *tmp = realloc(dictionary, counter);
		dictionary = tmp;
		counter++;

		printf("new word: ");
		fgets(line, sizeof(line), stdin);

		dictionary[counter - 2] = malloc(100);

		getchar();
	}

	return 0;
}
