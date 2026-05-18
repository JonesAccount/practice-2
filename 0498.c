#include <ncurses.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	initscr();
	mousemask(ALL_MOUSE_EVENTS, NULL);
	
	char ch;
	while ((ch = getch()) != 'q') {
		system("clear");
		printf("Pressed: %c\n", ch);
		refresh();
	}

	endwin();
	return 0;
}

// gcc 0498.c -lncurses -o app && ./app
