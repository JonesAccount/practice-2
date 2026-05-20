#include <ncurses.h>

int main(int argc, char *argv[]) {
	initscr();
	curs_set(0);
	
	start_color();
	// orange
	init_color(10, 1000, 500, 0); init_pair(1, 10, COLOR_BLACK);

	mvprintw(2, 13, "C A L C U L A T O R");
	mvprintw(4, 4, "+ - - - - - - - - - - - - - - - - - +");
	mvprintw(5, 4, "|"); 																											 mvprintw(5, 40, "|");
	mvprintw(6, 4, "+ - - - - - - - - - - - - - - - - - +");
	mvprintw(7, 4, "|"); 																			    						     mvprintw(7, 40, "|");
	mvprintw(8, 4, "|");  mvprintw(8, 5, "  (  ");  mvprintw(8, 15, "  )  ");  mvprintw(8, 25, "  %%  "); attron(COLOR_PAIR(1)); mvprintw(8, 35, "  C  ");  attroff(COLOR_PAIR(1)); color_set(0, NULL); mvprintw(8, 40, "|");
	mvprintw(9, 4, "|");  																										     mvprintw(9, 40, "|");
	mvprintw(10, 4, "|"); 																			   							     mvprintw(10, 40, "|");
	mvprintw(11, 4, "|"); mvprintw(11, 5, "  7  ");  mvprintw(11, 15, "  8  ");  mvprintw(11, 25, "  9  ");  mvprintw(11, 35, "  /  ");  mvprintw(11, 40, "|");
	mvprintw(12, 4, "|"); 																									 	     mvprintw(12, 40, "|");
	mvprintw(13, 4, "|");																											 mvprintw(13, 40, "|");
	mvprintw(14, 4, "|"); mvprintw(14, 5, "  4  "); mvprintw(14, 15, "  5  "); mvprintw(14, 25, "  6  "); mvprintw(14, 35, "  *  "); mvprintw(14, 40, "|");
	mvprintw(15, 4, "|"); 																									     	 mvprintw(15, 40, "|");
	mvprintw(16, 4, "|");																											 mvprintw(16, 40, "|");
	mvprintw(17, 4, "|"); mvprintw(17, 5, "  1  "); mvprintw(17, 15, "  2  "); mvprintw(17, 25, "  3  "); mvprintw(17, 35, "  -  "); mvprintw(17, 40, "|");
	mvprintw(18, 4, "|");																			                                 mvprintw(18, 40, "|");
	mvprintw(19, 4, "|");																							      		     mvprintw(19, 40, "|");
	mvprintw(20, 4, "|"); mvprintw(20, 5, "  0  "); mvprintw(20, 15, "  .  "); mvprintw(20, 25, "  =  "); mvprintw(20, 35, "  +  "); mvprintw(20, 40, "|");
 	mvprintw(21, 4, "|"); 																										     mvprintw(21, 40, "|");
   	mvprintw(22, 4, "+ - - - - - - - - - - - - - - - - - +");
  
	getch();

	curs_set(1); 
	endwin();
	return 0;
}

// gcc 0502.c -lncurses -o app && ./app
