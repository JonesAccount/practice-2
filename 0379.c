#include <ncurses.h>
#include <stdlib.h>

int main(void) {
	char ch;
	initscr();
	
	getch();
	ch = getch();
	
	printw("%c, ch");
	refresh();
	
	endwin();
	return 0;
}