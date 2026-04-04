#include <stdio.h>

int main(void) {
	printf("\033[?25l");
	printf("\033[1m16-ричная система\033[0m\n");

	int counter = 0;
	for (int i = 0; i < 10; i++) {
		printf("\033[33m0x%d\033[0m = %d\n", i, counter);
		counter++;
	}

	int letter = 65;
	for (int i = 0; i < 6; i++) {
		printf("\033[33m0x%c\033[0m = %d\n", letter, counter);
		letter++;
		counter++;
	}

	for (int i = 0; i < 10; i++) {
		printf("\033[33m0x1%d\033[0m = %d\n", i, counter);
		counter++;
	}

	getchar();

	return 0;
}
