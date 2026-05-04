#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main(void) {
	char *array = (char *)malloc(100);

	FILE *fp = fopen("dictionary.txt", "r");

	int counter = 0;
	char ch;
	while ((ch = getc(fp)) != EOF) {
		if (isalpha(ch)) {
			*(array + counter) = ch;
		} else {
			*(array + counter) = ' ';
		}

		counter++;
	}

	fclose(fp);

	for (int i = 0; i < counter; i++) {
		if (isalpha(*(array + i))) {
			printf("%c", *(array + i));
		} else {
			printf("\n");
		}
	}

	free(array);
	return 0;
}
