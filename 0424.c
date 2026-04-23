#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WHITE "\033[37;47m"
#define RESET "\033[0m"

void boom(void) {
	for (int i = 0; i < 5100; i++) {
		printf(WHITE "#");
	}
	usleep(100000);
	printf(RESET);
}

int main(void) {
	printf("\033[?25l");
	srand(time(NULL));
	fflush(stdout);
	
	while (1) {
		for (int i = 0; i < 3500; i++) {
			for (int j = 0; j < (rand() % (100 - 50 + 1) + 50); j++) {
				printf(" ");
			}
		
			printf("\\");
			usleep(1000);
	
		}
		
		system("clear");
		
		boom();
		
		system("clear");
		
	}
	
	getchar();
	return 0;
}