#include <ncurses.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	initscr();

	char ch;
	while ((ch = getch()) != 'q') {
		system("clear");
		printf("Pressed: %c\n", ch);
		refresh();
	}

	endwin();
	return 0;
}

// gcc 0497.c -lncurses -o app && ./app
