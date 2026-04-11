#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <time.h>

#define RAND rand() % (255 - 0 + 1) + 1

int main()
{
 srand(time(NULL));
 // инициализация SDL
 if (SDL_Init(SDL_INIT_VIDEO) != 0)
 {
  return 1;
 }

 TTF_Init();
 TTF_Font *font = TTF_OpenFont("Samson.ttf", 24);

 // создание окна
 SDL_Window *window;
 window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);

 // отображение
 SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

 SDL_Event event;

 bool running = true;
 int counter = 500;
 bool flag = true;
 int x = 250, y = 300;
 while (running)
 {
  // обработка выхода
  while (SDL_PollEvent(&event))
  {
   if (event.type == SDL_QUIT)
   {
    running = false;
   }
  }

  SDL_SetRenderDrawColor(renderer, 90, 150, 255, 0);

  SDL_RenderClear(renderer);

  SDL_SetRenderDrawColor(renderer, 100, 200, 50, 0);
  SDL_Rect square;
  square.x = x;
  square.y = y;
  square.w = counter;
  square.h = counter;
  SDL_RenderFillRect(renderer, &square);

  SDL_Color color = {255, 0, 0};
  SDL_Surface *surface = TTF_RenderText_Solid(font, "Hi SDL", color);
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);
  SDL_Rect dest = {100, 100, 200, 50};
  SDL_RenderCopy(renderer, texture, NULL, &dest);
  SDL_DestroyTexture(texture);

  SDL_RenderPresent(renderer);

  SDL_Delay(1);
 }

 // закрытие окна и выход из SDL
 SDL_DestroyWindow(window);
 SDL_Quit();

 return 0;
}