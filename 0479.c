#include <string.h>
#include <stdio.h>

int main(void) {
	FILE *file = fopen("text.txt", "r");

	if (NULL == file) { printf("error shit"); return 1; }

	if (file) {
		char ch;

		while ((ch = getc(file)) != EOF) {
			printf("%c", ch);
		}

		fclose(file);
	}

	return 0;
}
