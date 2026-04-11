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

	while (running) {
		while (SDL_PollEvent(&event) != 0) {
			switch (event.type) {
				case SDL_QUIT:
					running = 0;
					break;
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym) {
						case SDLK_w: y -= 10; break;
						case SDLK_s: y += 10; break;
						case SDLK_d: x += 10; break;
						case SDLK_a: x -= 10;
					}
			}
		}

		square.x = x;
		square.y = y;

		SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 255, 255));
		SDL_FillRect(surface, &square, SDL_MapRGB(surface->format, 0, 50, 255));
		SDL_UpdateWindowSurface(window);

	}

	quit();

	return 0;
}
