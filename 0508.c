#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#include "raylib.h"
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
#define WINDOW_X 1000
#define WINDOW_Y 800

#define SPEED 400
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
typedef struct {
	int x, y;
} Move;

int main(int argc, char *argv[]) {
	InitWindow(WINDOW_X, WINDOW_Y, "Program");
	srand((unsigned)time(NULL));
	
	int x = 0;
	SetTargetFPS(SPEED);
	Move move = {WINDOW_X / 2, WINDOW_Y / 2};
	
	Rectangle player = {move.x, move.y - 10, 50, 50};
	Rectangle star = {move.x, move.y - 10, 50, 50};
	Rectangle wall1 = {(WINDOW_X - 50)  / 2, (WINDOW_Y + 100) / 2, 50, 200};
	Rectangle wall2 = {(WINDOW_X - 500) / 2, (WINDOW_Y - 250) / 2, 150, 50};
	Rectangle wall3 = {(WINDOW_X + 200) / 2, (WINDOW_Y - 250) / 2, 150, 50};
	Rectangle wall4 = {100, (WINDOW_Y + 500) / 2, WINDOW_X * 0.8, 50};
	Rectangle wall5 = {100, 100, WINDOW_X * 0.8, 50};
	Rectangle wall6 = {100, 100, 50, WINDOW_Y * 0.7};
	Rectangle wall7 = {WINDOW_X * 0.8 + 50, 100, 50, WINDOW_Y * 0.7};
	
	while (!WindowShouldClose()) {
		float oldX = move.x;
		float oldY = move.y;
		
		// movement
		if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) { move.x++; }
		if (IsKeyDown(KEY_LEFT)  || IsKeyDown(KEY_A)) { move.x--; }
		if (IsKeyDown(KEY_DOWN)  || IsKeyDown(KEY_S)) { move.y++; }
		if (IsKeyDown(KEY_UP)    || IsKeyDown(KEY_W)) { move.y--; }
		
		player.x = move.x;
		player.y = move.y;
	
		if (CheckCollisionRecs(player, wall1) ||
			CheckCollisionRecs(player, wall2) ||
			CheckCollisionRecs(player, wall3) ||
			CheckCollisionRecs(player, wall4) ||
			CheckCollisionRecs(player, wall5) ||
			CheckCollisionRecs(player, wall6) ||
			CheckCollisionRecs(player, wall7)) {
			move.x = oldX;
			move.y = oldY;
		}
		
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		BeginDrawing();
		ClearBackground(GRAY);

		// player
		DrawRectangleRec(player, (Color){80, 0, 0, 255});
		
		// walls
		DrawRectangleRec(wall1, BLACK);
		DrawRectangleRec(wall2, BLACK);
		DrawRectangleRec(wall3, BLACK);
		DrawRectangleRec(wall4, BLACK);
		DrawRectangleRec(wall5, BLACK);
		DrawRectangleRec(wall6, BLACK);
		DrawRectangleRec(wall7, BLACK);
		
		// score
		DrawText(TextFormat("Score: %d", 0), 1, 1, 50, BLACK);
		
		EndDrawing();
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	}

	CloseWindow();
	return 0;
}

// gcc 0508.c -o game -I/opt/homebrew/opt/raylib/include -L/opt/homebrew/opt/raylib/lib -lraylib -lm -lpthread -ldl -framework OpenGL -framework Cocoa -framework IOKit && ./game