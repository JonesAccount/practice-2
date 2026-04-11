#include "SDL.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char **argv) {
	// инициализация модулей
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { return 1; }

	// создание окна
	SDL_Window* window = SDL_CreateWindow("Program", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (NULL == window) { return 1; }

	// поверхность окна для рисования
	SDL_Surface* screen_surface = SDL_GetWindowSurface(window);
	SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 0, 255, 0));
	SDL_UpdateWindowSurface(window);

	SDL_Delay(5000);
	
	// завершение программы
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
