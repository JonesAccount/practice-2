#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	printf("\033[?25l");
	fflush(stdout);
	
	int speed = 100000;
	while (1) {
		printf("\n\t•\n");
		usleep(speed);
		system("clear");
		
		printf("\n\n\n\n\n\t•\n");
		usleep(speed);
		system("clear");
		
		speed -= 1;
	}
	return 0;
}