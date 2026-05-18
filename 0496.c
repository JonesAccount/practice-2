#include <ncurses.h>

int main(int argc, char *argv[]) {
	initscr();
	printw("Hi");
	refresh();
	getch();
	endwin();

	return 0;
}

// gcc 0496.c -lncurses -o app && ./app