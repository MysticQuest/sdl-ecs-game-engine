#include <SDL.h>
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Window Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,800, 600, SDL_WINDOW_SHOWN);
}
