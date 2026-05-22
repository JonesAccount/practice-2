#include "raylib.h"

#define WINDOW_X 700
#define WINDOW_Y 700

int main(int argc, char *argv[]) {
	InitWindow(WINDOW_X, WINDOW_Y, "Program");
	
	while (!WindowShouldClose()) {
		BeginDrawing();
		
		ClearBackground(BLACK);
		DrawRectangle((WINDOW_X - 250) / 2, 1, 250, 250, GREEN);
		DrawRectangle((WINDOW_X - 200) / 2, 250 + 1, 200, 200, RED);
		DrawRectangle((WINDOW_X - 150) / 2, 250 + 200 + 1, 150, 150, BLUE);
		DrawRectangle((WINDOW_X - 100) / 2, 250 + 200 + 150 + 1, 100, 100, YELLOW);
		
		EndDrawing();
	}

	CloseWindow();
	return 0;
}

// gcc 0504.c -o game -I/opt/homebrew/opt/raylib/include -L/opt/homebrew/opt/raylib/lib -lraylib -lm -lpthread -ldl -framework OpenGL -framework Cocoa -framework IOKit && ./game