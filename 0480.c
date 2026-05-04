#include <string.h>
#include <stdio.h>

int main(void) {
	FILE *file = fopen("text.txt", "w");
	if (NULL == file) { printf("error shit"); return 1; }

	if (file) {
		char word[50];
		printf("input: ");
		fgets(word, 49, stdin);

		for (int i = 0; i < strlen(word); i++) {
			putc(word[i], file);
		}

		fclose(file);
	}

	file = fopen("text.txt", "r");
	if (NULL == file) { printf("error shit"); return 1; }

	if (file) {
		char ch[50];
		fgets(ch, 50, file);
		printf("output: %s", ch);

		fclose(file);
	}

	return 0;
}
