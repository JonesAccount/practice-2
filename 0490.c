#include <stdbool.h>
#include <stdio.h>
#include <SDL.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(int argc, char *argv[]) {
	// window
	SDL_Window *window = NULL;

	// container for by window
	SDL_Surface *screenSurface = NULL;

	// inicialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL error: %s\n", SDL_GetError());
	} else {
		window = SDL_CreateWindow("My first program", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (NULL == window) {
			printf("SDL error: %s\n", SDL_GetError());
		} else {
			screenSurface = SDL_GetWindowSurface(window);
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
			SDL_UpdateWindowSurface(window);
			SDL_Event e;
			bool quit = false;
			while (quit == false) {
				while (SDL_PollEvent(&e)) {
					if (e.type == SDL_QUIT) { quit = true; }
				}
			}
		}
	}

	SDL_Delay(10000);

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

// gcc 0490.c -o game $(pkg-config --cflags --libs sdl2) && ./game
