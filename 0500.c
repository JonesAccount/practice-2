#include <ncurses.h>

int main(void) {
    initscr();
    
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS, NULL); 
    MEVENT event;
    
    while (1) {
    	int ch = getch();
    	
    	if (ch == KEY_MOUSE) {
    		if (getmouse(&event) == OK) {
    			
    			clear();
    			
    			mvprintw(10, 10,
    				"Mouse: %d %d",
    				event.x,
    				event.y);
    				
    			refresh();
    		}
    	}
    }
   
    endwin();
    return 0;
}