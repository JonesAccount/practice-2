#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef unsigned int uint;
typedef char ch;
typedef double dbl;


typedef struct {
	uint *price;
	ch *color;
	dbl *height;
} Notepad;

Notepad ntp[3];


int main(void) {
	printf("\033[?25l");

	char line[21]; char *pL = line;
	for (int i = 0; i < 20; i++)
		pL[i] = '-';

	// Ноутбук 1
	ntp[0].price = malloc(sizeof(uint)); if (!ntp[0].price) return 1;
	*ntp[0].price = 1000;

	ntp[0].color = malloc(50 * sizeof(ch)); if (!ntp[0].color) return 1;
	strcpy(ntp[0].color, "серый");

	ntp[0].height = malloc(sizeof(dbl)); if (!ntp[0].height) return 1;
	*ntp[0].height = 1.2;

	printf("Ноутбук 1\n");
	printf("\nЦена: %u$", *ntp[0].price);
	printf("\nЦвет: \033[1;30m%s\033[0m", ntp[0].color);
	printf("\nВес: %.1lf кг.", *ntp[0].height);

	printf("\n%s", line);

	// Ноутбук 2
	ntp[1].price = malloc(sizeof(uint)); if (!ntp[1].price) return 1;
	*ntp[1].price = 850;

	ntp[1].color = malloc(50 * sizeof(ch)); if (!ntp[1].color) return 1;
	strcpy(ntp[1].color, "белый");

	ntp[1].height = malloc(sizeof(dbl)); if (!ntp[1].height) return 1;
	*ntp[1].height = 1.5;

	printf("\nНоутбук 2\n");
	printf("\nЦена: %u$", *ntp[1].price);
	printf("\nЦвет: %s", ntp[1].color);
	printf("\nВес: %.1lf кг.", *ntp[1].height);

	printf("\n%s", line);

	// Ноутбук 3
	ntp[2].price = malloc(sizeof(uint)); if (!ntp[2].price) return 1;
	*ntp[2].price = 2300;

	ntp[2].color = malloc(50 * sizeof(ch)); if (!ntp[2].color) return 1;
	strcpy(ntp[2].color, "синий");

	ntp[2].height = malloc(sizeof(dbl)); if (!ntp[2].height) return 1;
	*ntp[2].height = 2.3;

	printf("\nНоутбук 3\n");
	printf("\nЦена: %u$", *ntp[2].price);
	printf("\nЦвет: \033[34m%s\033[0m", ntp[2].color);
	printf("\nВес: %.1lf кг.", *ntp[2].height);


	free(ntp[0].price); free(ntp[1].price); free(ntp[2].price);

	getchar(); getchar();

	return 0;
}
