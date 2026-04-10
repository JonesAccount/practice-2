#include <stdbool.h>
#include "SDL.h"

int main(int argc, char* argv[]) {
	if ((SDL_Init(SDL_INIT_VIDEO) == 1)) { return 1; }

	SDL_Window* window;
	SDL_Renderer* renderer;
	window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_Event event;
	bool running = true;

	while (running) {

		while (SDL_PollEvent(&event)) {

		}

		SDL_Delay(1000);
	}

	SDL_DestroyWindow(window);

	return 0;
}
