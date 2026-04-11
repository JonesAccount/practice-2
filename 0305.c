#include <SDL2/SDL.h>
#include <stdbool.h>

int main() {
 // инициализация SDL
 if (SDL_Init(SDL_INIT_VIDEO) != 0) { return 1; }
 
 // создание окна
 SDL_Window* window;
 window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
 
 SDL_Event event;
 
 bool running = true;
 while (running) {
  
  // обработка выхода
  while (SDL_PollEvent(&event)) {
   if (event.type == SDL_QUIT) {
    running = false;
   }
  }
  
  printf("Hi");
  SDL_Delay(1000);
 }

 // закрытие окна
 SDL_DestroyWindow(window);
 
 return 0;
}