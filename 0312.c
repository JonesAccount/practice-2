#include <stdlib.h>
#include <time.h>
#include "SDL.h"

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 800;

SDL_Window *window = NULL;
SDL_Surface *surface = NULL;

int init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("Error: %s\n", SDL_GetError());
		(void)getchar();
		return 1;
	}

	window = SDL_CreateWindow("program", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (NULL == window) {
		printf("Error: %s\n", SDL_GetError());
		(void)getchar();
		return 1;
	}

	surface = SDL_GetWindowSurface(window);

	return 0;
}

int quit() {
	SDL_FreeSurface(surface);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

int main(int argc, char **args) {
	if (init() == 1) { return 1; }

	srand(time(NULL));

	int running = 1;
	SDL_Event event;

	int x = 100, y = 100;
	SDL_Rect square = {x, y, 100, 100};
	SDL_Rect wall = {700, 150, 100, 400};

	while (running) {
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				running = 0;
			}
		}

		const Uint8 *keys = SDL_GetKeyboardState(NULL);
		if (keys[SDL_SCANCODE_W]) { y--; }
		if (keys[SDL_SCANCODE_S]) { y++; }
		if (keys[SDL_SCANCODE_A]) { x--; }
		if (keys[SDL_SCANCODE_D]) { x++; }

		square.x = x;
		square.y = y;

		SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 255, 255));
		SDL_FillRect(surface, &square, SDL_MapRGB(surface->format, 226, 172, 2));
		SDL_FillRect(surface, &wall, SDL_MapRGB(surface->format, 0, 0, 0));
		SDL_UpdateWindowSurface(window);

	}

	quit();

	return 0;
}
