#include <memory>
#include "Game.h"
#include "Entity.h"

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

void Game::Render(SDLWindow& sdlWindow, const std::vector<Entity>& entities)
{
    sdlWindow.Clear();
    for (const auto& entity : entities)
    {
        sdlWindow.Render(entity);
    }
    sdlWindow.Display();
}

void Game::Update()
{

}

void Game::Run(SDLWindow& sdlWindow)
{
    SDL_Texture* testTexture = sdlWindow.LoadTexture("res/textures/pac1.png");
    Entity prototype(150, 150, testTexture);
    std::vector<Entity> entities(200000, prototype);

    Uint32 before, second = SDL_GetTicks(), after;
    int frame_time, frames = 0;

    while (isRunning)
    {
        before = SDL_GetTicks();

        PollEvents();

        Update();

        Render(sdlWindow, entities);
        
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

