#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#include "raylib.h"

#define WINDOW_X 700
#define WINDOW_Y 700

#define WIDTH 50
#define HEIGHT 50

#define SPEED 60

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
	InitWindow(WINDOW_X, WINDOW_Y, "IDK");
	srand((unsigned)time(NULL));

	float timer = 0;q
	int count = 0;

	SetTargetFPS(SPEED);

	while (!WindowShouldClose()) {
		timer += GetFrameTime();

		if (timer > 0.10f) {
			count++;
			timer = 0;
		}

		BeginDrawing();

		for (int i = 0; i < count; i++) {
			DrawRectangle(rand() % (WINDOW_X - WIDTH) + 1, rand() % (WINDOW_Y - HEIGHT) + 1, WIDTH, HEIGHT, color);
			change_color();
		}

		EndDrawing();
	}

	CloseWindow();
	return 0;
}

// gcc 0507.c -o game -I/opt/homebrew/opt/raylib/include -L/opt/homebrew/opt/raylib/lib -lraylib -lm -lpthread -ldl -framework OpenGL -framework Cocoa -framework IOKit && ./game
