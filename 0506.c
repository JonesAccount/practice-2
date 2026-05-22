#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#include "raylib.h"

#define WINDOW_X 700
#define WINDOW_Y 700

#define WIDTH 100
#define HEIGHT 100

#define SPEED 350

Color color = BLACK;

void change_color(void) {
	static int index = 0;
	index = rand() % 12 + 1;
	
	switch (index) {
		case 1: color = RED;     break;
		case 2: color = BLUE;    break;
		case 3: color = GREEN;   break;
		case 4: color = ORANGE;  break;
		case 5: color = GOLD;    break;
		case 6: color = LIME;    break;
		case 7: color = PURPLE;  break;
		case 8: color = VIOLET;  break;
		case 9: color = BROWN;   break;
		case 10: color = BEIGE;   break;
		case 11: color = SKYBLUE; break;
		case 12: color = MAROON;  break;
		
	}
}

int main(int argc, char *argv[]) {
	InitWindow(WINDOW_X, WINDOW_Y, "Program");
	srand((unsigned)time(NULL));
	
	int x = 0;
	SetTargetFPS(SPEED);
	bool flag = true;
	
	while (!WindowShouldClose()) {
		
		if (x == WINDOW_X - WIDTH) {
			flag = false;
			change_color();
		} else if (x == 0) {
			flag = true;
			change_color();
		}
		
		if (flag) {
			x++;
		} else {
			x--;
		}
		
		BeginDrawing();
		
		ClearBackground(GRAY);
		// frame
		DrawRectangle(x - 5, (WINDOW_Y - 100 - 10) / 2, WIDTH + 10, HEIGHT + 10, BLACK);
		// square
		DrawRectangle(x, (WINDOW_Y - 100) / 2, WIDTH, HEIGHT, color);
		
		EndDrawing();
	}

	CloseWindow();
	return 0;
}

// gcc 0506.c -o game -I/opt/homebrew/opt/raylib/include -L/opt/homebrew/opt/raylib/lib -lraylib -lm -lpthread -ldl -framework OpenGL -framework Cocoa -framework IOKit && ./game