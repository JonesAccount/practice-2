#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int size = 3;

void print_nums(int *);
void fill_nums(int *);
void plus(int *);
void minus(int *);
char getch(void);
void clear_screen(void);

int main(void) {
	printf("\033[?25l");
	
	auto int *nums = (int *)malloc(size * sizeof(int));
	if (NULL == nums) { printf("error"); return 1; }

	auto char ch = 0;
	
	while(1) {
		fill_nums(nums);
		print_nums(nums);
		
		ch = getch();
		
		clear_screen();
		switch (ch) {
			case '1': plus(nums); break;
			case '0': minus(nums);
		}
	}
	
	return 0;
}


void print_nums(int *nums) {
	for (size_t i = 0; i < size; i++) {
		if (!i) { printf("Массив:\n"); }
		printf("%d ", *(nums + i));
		if (i == size - 1) { printf("\n[1] увеличить [0] уменьшить"); }
	}
}

void fill_nums(int *nums) {
	for (size_t i = 0; i < size; i++) {
		*(nums + i) = i + 1;
	}
}

void plus(int *nums) {
	printf("[?] ");
	int in = 0;
	scanf("%d", &in);
	size += in;
	
	int *tmp = realloc(nums, size * sizeof(int));
	if (NULL == tmp) { printf("error"); return; }
	
	nums = tmp;
}

void minus(int *nums) {
	printf("[?] ");
	int in = 0;
	scanf("%d", &in);
	size -= in;
	
	int *tmp = realloc(nums, size * sizeof(int));
	if (NULL == tmp) { printf("error"); return; }
	
	nums = tmp;
}


char getch(void) {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);       
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);    
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); 
    return ch;
}

void clear_screen(void) {
    fputs("\033[2J\033[H", stdout);
    fflush(stdout);
}