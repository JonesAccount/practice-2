#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>	

#define SIZE 2

void print_arr(int *arr) {
	for (size_t i = 0; i < SIZE; i++) {
		printf("%d ", *(arr + i));
		if (i == SIZE - 1) { printf("\n\n"); }
	}
}

void fill_arr(int *arr) {
	for (size_t i = 0; i < SIZE; i++) {
		*(arr + i) = 1;
	}
}

void add_el(int **arr, int els) {
	int *tmp = realloc(**arr, els * sizeof(int));
	if (NULL == tmp) { printf("error"); return; }
	
	**arr = tmp;
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

int main(void) {
	
	{
		printf("\033[?25l");
	}
	
	
	while (1) {
		int *arr = (int *)calloc(sizeof(int), SIZE);
		if (NULL == arr) { return 1; }
	
		fill_arr(arr);
		print_arr(arr);
		
		char ch = getch();
		
		switch (ch) {
			
		}
		
		
		add_el(*arr, 3);
		print_arr(arr);
		
		(void)getchar();
	}
	
	
	{
		return 0;
	}
}