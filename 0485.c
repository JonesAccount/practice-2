#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char *a = malloc(100);

	char word[] = {"jsdlfjsfsksknsd"};
	for (int i = 0; i < strlen(word); i++) {
		*(a + i) = word[i];
	}

	char ch;
	int cntr = 0;
	while ((ch = *(a + cntr)) != EOF) {
		cntr++;
		printf("%c", ch);
	}

	return 0;
}
