#include <stdio.h>

int my_strlen(char *s) {
	int counter = 0;
	int *pC = &counter;

	while (*s != '\0') {
		(*pC)++;
		s++;
	}

	return *pC;
}

int main(void) {
	printf("\033[?25l");

	int size;
	int *pS = &size;
	*pS = 0;

	*pS = my_strlen("fuck");
	printf("%d\n", *pS);

	return 0;
}
