#include <SDL.h>
#include <iostream>
#include <memory>
#include "Game.h"
#include "SDLWindow.h"


Game* game = nullptr;

int main(int argc, char* argv[])
{
    std::unique_ptr<SDLWindow> window = std::make_unique<SDLWindow>("Test Title", 800, 600);
    SDL_Event event;
    while (window->Running())
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) {}
        }
    }


    //try
    //{
    //    std::cout << "Game has terminated successfully, score: " << std::endl;
    //}
    //catch (std::exception const& e)
    //{
    //    std::cerr << e.what();
    //}


    //game = new Game();
    //game->Initialize("Test Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    //while (game->Running())
    //{
    //    game->HandleEvents();
    //    game->Update();
    //    game->Render();
    //}

    //game->Clean();

    return 0;
}
