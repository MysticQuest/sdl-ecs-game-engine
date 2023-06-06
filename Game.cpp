#include <memory>
#include "Game.h"

Game::Game(std::unique_ptr<SDLWindow> sdlWindow, int frame_rate)
{
    frame_rate = frame_rate;
    Run();
}

Game::~Game() 
{
}

void Game::PollEvents(bool& quit)
{
    // ...
}

void Game::Render()
{

}

void Game::Update()
{

}

void Game::Run()
{
    Uint32 before, second = SDL_GetTicks(), after;
    int frame_time, frames = 0;

    while (true)
    {
        before = SDL_GetTicks();

        bool quit = false;
        PollEvents(quit);

        if (quit)
            break;

        Update();

        Render();

        frames++;
        after = SDL_GetTicks();
        frame_time = after - before;

        if (after - second >= 1000)
        {
            frames = 0;
            second = after;
        }

        if (frame_rate > frame_time)
        {
            SDL_Delay(frame_rate - frame_time);
        }
    }
}

