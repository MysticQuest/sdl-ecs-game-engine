#include <memory>
#include "Game.h"

Game::Game(SDLWindow& sdlWindow, int frame_rate)
{
    frame_rate = frame_rate;
    Run(sdlWindow);
}

Game::~Game() 
{

}

void Game::PollEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT)
    {
        isRunning = false;
    }
}

void Game::Render()
{

}

void Game::Update()
{

}

void Game::Run(SDLWindow& sdlWindow)
{
    Uint32 before, second = SDL_GetTicks(), after;
    int frame_time, frames = 0;

    SDL_Texture* testTexture = sdlWindow.LoadTexture("res/textures/pac1.png");

    while (isRunning)
    {
        before = SDL_GetTicks();

        PollEvents();

        Update();

        sdlWindow.Clear();
        sdlWindow.Render(testTexture);
        sdlWindow.Display();

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

