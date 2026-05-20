#include <ncurses.h>

void calc_print(void);

int main(int argc, char *argv[]) {
	initscr();
	curs_set(0);

	calc_print();
	getch();
	
	curs_set(1);
	endwin();
	return 0;
}

void calc_print(void) {
	// settings color
	start_color();
	use_default_colors();
	init_pair(1, 10, -1);  // terminal default color 
	init_pair(1, 202, -1); // orange
	
	attron(A_BOLD);

	// frames - - - - - - - - - - - - - - - - - - - 
	for (int i = 5; i <= 21; i++) {
		if (i != 6) { mvprintw(i, 4, "|"); }
	}
	
	for (int i = 7; i <= 21; i++) {
		mvprintw(i, 40, "|");
	}
	
	for (int i = 5; i <= 21; i++) {
		if (i != 6) { mvprintw(i, 96, "|"); }
	}
	
	// lines - - - - - - - - - - - - - - - - - - - 
	for (int i = 4; i <= 97; i += 2) {
		if (i != 4 && i != 40 && i != 96) {
			mvprintw(4, i, "-");
		} else {
			mvprintw(4, i, "+");
		}
	}
	
	for (int i = 4; i <= 97; i += 2) {
		if (i != 4 && i != 40 && i != 96) {
			mvprintw(6, i, "-");
		} else {
			mvprintw(6, i, "+");
		}
	}
	
	for (int i = 4; i <= 97; i += 2) {
		if (i != 4 && i != 40 && i != 96) {
			mvprintw(22, i, "-");
		} else {
			mvprintw(22, i, "+");
		}
	}

	mvprintw(5, 13, "C A L C U L A T O R");																																				        mvprintw(5, 40, "|");
	attron(COLOR_PAIR(1));    mvprintw(8, 5, "  (  ");   mvprintw(8, 15, "  )  ");  mvprintw(8, 25, "  %%  "); mvprintw(8, 35, "  C  ");  attroff(COLOR_PAIR(1));
	mvprintw(11, 5, "  7  "); mvprintw(11, 15, "  8  "); mvprintw(11, 25, "  9  "); attron(COLOR_PAIR(1));     mvprintw(11, 35, "  /  "); attroff(COLOR_PAIR(1));
	mvprintw(14, 5, "  4  "); mvprintw(14, 15, "  5  "); mvprintw(14, 25, "  6  "); attron(COLOR_PAIR(1));     mvprintw(14, 35, "  *  "); attroff(COLOR_PAIR(1));
	mvprintw(17, 5, "  1  "); mvprintw(17, 15, "  2  "); mvprintw(17, 25, "  3  "); attron(COLOR_PAIR(1));     mvprintw(17, 35, "  -  "); attroff(COLOR_PAIR(1));
	mvprintw(20, 5, "  0  "); mvprintw(20, 15, "  .  "); mvprintw(20, 25, "  =  "); attron(COLOR_PAIR(1));     mvprintw(20, 35, "  +  "); attroff(COLOR_PAIR(1));
 	
}

// gcc 0502.c -lncurses -o app && ./app
