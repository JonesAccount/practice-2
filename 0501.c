#include <ncurses.h>

int main(int argc, char *argv[]) {
	initscr();
	curs_set(0);

	mvprintw(1, 1, "-");
	mvprintw(5, 10, "[  (  ]");  mvprintw(5, 23, "[  )  ]");  mvprintw(5, 36, "[  %%  ]"); mvprintw(5, 49, "[  C  ]");
	mvprintw(8, 10, "[  7  ]");  mvprintw(8, 23, "[  8  ]");  mvprintw(8, 36, "[  9  ]");  mvprintw(8, 49, "[  /  ]");
	mvprintw(11, 10, "[  4  ]");  mvprintw(11, 23, "[  5  ]");  mvprintw(11, 36, "[  6  ]");  mvprintw(11, 49, "[  *  ]");
	mvprintw(14, 10, "[  1  ]"); mvprintw(14, 23, "[  2  ]"); mvprintw(14, 36, "[  3  ]"); mvprintw(14, 49, "[  -  ]");
	mvprintw(17, 10, "[  0  ]"); mvprintw(17, 23, "[  .  ]"); mvprintw(17, 36, "[  =  ]"); mvprintw(17, 49, "[  +  ]");
 	
	getch();

	curs_set(1); 
	endwin();
	return 0;
}

// gcc 0501.c -lncurses -o app && ./app
