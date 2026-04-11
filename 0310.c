#include <stdlib.h>
#include <time.h>
#include "SDL.h"

#define RAND rand() % (500 - 1 + 1) + 1
#define SIZE rand() % (30 - 10 + 1) + 1
#define R_COLOR rand() % (255 - 0 + 1) + 1
#define COUNT 1000

const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 500;

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

	while (running) {
		while (SDL_PollEvent(&event) != 0) { if (event.type == SDL_QUIT) { running = 0; } }

		SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0, 0, 0));

		int size;
		for (int i = 0; i < COUNT; i++) {
			size = SIZE;
			SDL_Rect square = {RAND, RAND, size, size};

			SDL_FillRect(surface, &square, SDL_MapRGB(surface->format, R_COLOR, R_COLOR, R_COLOR));
			SDL_UpdateWindowSurface(window);

			SDL_Delay(10);
		}

	}

	quit();

	return 0;
}
