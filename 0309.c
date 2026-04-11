#include "SDL.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window *win = NULL;
SDL_Surface *scr = NULL;
SDL_Surface *john = NULL;

int init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("Error: %s\n", SDL_GetError());
		(void)getchar();
		return 1;
	}
	
	win = SDL_CreateWindow("profram", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (NULL == win) {
		printf("Error: %s\n", SDL_GetError());
		(void)getchar();
		return 1;
	}
	
	scr = SDL_GetWindowSurface(win);
	
	return 0;
}

int load() {
	john = SDL_LoadBMP("john.bmp");
	
	if (NULL == john) {
		printf("Error: %s\n", SDL_GetError());
		(void)getchar();
		return 1;
	}
	
	return 0;
}

int quit() {
	SDL_FreeSurface(john);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}

int main(int argc, char **args) {
	if (init() == 1) { return 1; }
	if (load() == 1) { return 1; }
	
	int run = 1, x = 0, y = 0;
	
	SDL_Event e;
	SDL_Rect r;
	
	r.x = x;
	r.y = y;
	
	while (run) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				run = 0;
			}
			
			if (e.type == SDL_KEYDOWN) {
				if (e.key.keysym.sym == SDLK_UP) {
					y -= 1;
				}
				if (e.key.keysym.sym == SDLK_DOWN) {
					y += 1;
				}
				if (e.key.keysym.sym == SDLK_RIGHT) {
					x += 1;
				}
				if (e.key.keysym.sym == SDLK_LEFT) {
					x -= 1;
				}
			}
		}
		
		r.x = x;
		r.y = y;
		
		SDL_FillRect(scr, NULL, SDL_MapRGB(scr -> format, 255, 255, 255));
		SDL_BlitSurface(john, NULL, scr, &r);
		SDL_UpdateWindowSurface(win);
	}
	
	
	quit();
	
	return 0;
}