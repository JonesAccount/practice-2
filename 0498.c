#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#define B "[BUTTON]"

int main(int argc, char *argv[]) {
	initscr();
	keypad(stdscr, TRUE);
	mousemask(ALL_MOUSE_EVENTS, NULL);
	
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);

	MEVENT event;
	int ch;
	int clicked = 2;
	
	while ((ch = getch()) != 'q') {
		clear();
		
		if (clicked == 1) {
			attron(COLOR_PAIR(1));
		} else {
			attroff(COLOR_PAIR(1));
		}
		
		mvprintw(1, 1, B);
		
		if (clicked == 1) {
			attron(COLOR_PAIR(1));
			clicked = 2;
		} else {
			attroff(COLOR_PAIR(1));
		}
		
		if (ch == KEY_MOUSE) {
			if (getmouse(&event) == OK) {
				if (event.y >= 1 &&
					event.x >= 1 &&
					event.x <= (int)strlen(B)) {
					mvprintw(5, 1, "CLICKED!");
					clicked = 1;
				}
			}
		}
		refresh();
	}

	endwin();
	return 0;
}

// gcc 0498.c -lncurses -o app && ./app
