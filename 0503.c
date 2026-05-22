#include "raylib.h"

int main(int argc, char *argv[]) {
	InitWindow(800, 450, "Window");
	
	while (!WindowShouldClose()) {
		BeginDrawing();
		
		ClearBackground(RAYWHITE);
		DrawText("My first program in Raylib", 75, 200, 50, DARKGRAY);
		
		EndDrawing();
	}

	CloseWindow();
	return 0;
}

// gcc 0503.c -o game -I/opt/homebrew/opt/raylib/include -L/opt/homebrew/opt/raylib/lib -lraylib -lm -lpthread -ldl -framework OpenGL -framework Cocoa -framework IOKit && ./game