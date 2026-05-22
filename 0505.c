#include <stdbool.h>
#include "raylib.h"

#define WINDOW_X 700
#define WINDOW_Y 700

#define WIDTH 100
#define HEIGHT 100

int main(int argc, char *argv[]) {
	InitWindow(WINDOW_X, WINDOW_Y, "Program");
	
	int x = 0;
	SetTargetFPS(250);
	
	while (!WindowShouldClose()) {
		static bool flag = true;
		
		if (x == WINDOW_X - WIDTH) {
			flag = false;
		} else if (x == 0) {
			flag = true;
		}
		
		if (flag) {
			x++;
		} else {
			x--;
		}
		
		BeginDrawing();
		
		ClearBackground(BLACK);
		DrawRectangle(x, (WINDOW_Y - 100) / 2, WIDTH, HEIGHT, RED);
		
		EndDrawing();
	}

	CloseWindow();
	return 0;
}

// gcc 0505.c -o game -I/opt/homebrew/opt/raylib/include -L/opt/homebrew/opt/raylib/lib -lraylib -lm -lpthread -ldl -framework OpenGL -framework Cocoa -framework IOKit && ./game