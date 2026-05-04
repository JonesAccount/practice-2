#include <string.h>
#include <stdio.h>

int main(void) {
	FILE *file = fopen("text.txt", "w");

	if (NULL == file) { printf("error shit"); return 1; }

	if (file) {
		char word[10];
		printf("Word: ");
		scanf("%9s", word);

		for (int i = 0; i < strlen(word); i++) {
			putc(word[i], file);
		}

		fclose(file);
	}

	return 0;
}
