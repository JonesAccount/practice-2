#include "raylib.h"

#define WINDOW_X 700
#define WINDOW_Y 700

int main(int argc, char *argv[]) {
	InitWindow(WINDOW_X, WINDOW_Y, "Program");
	
	while (!WindowShouldClose()) {
		BeginDrawing();
		
		ClearBackground(BLACK);
		DrawText(".", 350, 250, 150, RED);
		DrawText("It is me!", 190, 50, 100, DARKGRAY);
		DrawText("code", WINDOW_X / 2 - 70, 500, 80, DARKGRAY);
		
		EndDrawing();
	}

	CloseWindow();
	return 0;
}

// gcc 0504.c -o game -I/opt/homebrew/opt/raylib/include -L/opt/homebrew/opt/raylib/lib -lraylib -lm -lpthread -ldl -framework OpenGL -framework Cocoa -framework IOKit && ./game