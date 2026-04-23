#include <unistd.h>
#include <stdio.h>

#define N "\n"

void clear_screen(void) {
    fputs("\033[2J\033[H", stdout);
    fflush(stdout);
}

int main(void) {
	printf("\033[?25l");
	fflush(stdout);
	
	int time[5] = {0};
	
	while (1) {
		printf("Время" N N);
		printf("Дни: %d" N "Часы: %d" N "Минуты: %d" N "Секунды: %d" N "Милисекунды: %d" N, *time, *time, *(time + 1), time[2], *(time + 3));

		time[4]++;
		
		if (*(time + 4) == 100) {
			*(time + 4) = 0;
			time[3]++;
		}
		
		if (*(time + 3) == 60) {
			*(time + 3) = 0;
			time[2]++;
		}
		
		if (*(time + 2) == 60) {
			*(time + 2) = 0;
			time[1]++;
		}
		
		if (*(time + 1) == 24) {
			*(time + 1) = 0;
			(*time)++;
		}

		usleep(100); // 10.000 = 1/100 милисекунды (100 м == 1 с)
		clear_screen();
	}
	
	return 0;
}