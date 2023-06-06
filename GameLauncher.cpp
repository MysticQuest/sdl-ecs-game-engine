#include <memory>
#include "GameLauncher.h"

std::string filePath = "settings.ini";

GameLauncher::GameLauncher(Game game)
{




}

//GameLauncher::~GameLauncher()
//{
//}
//
//void GameLauncher::PollEvents(SDLWindow&, bool& quit)
//{
//    // ...
//}
//
//void GameLauncher::Render(SDLWindow&, GameLauncher const& game)
//{
//
//    SDL_Event event;
//    //while (window->Running())
//    //{
//    //    while (SDL_PollEvent(&event))
//    //    {
//    //        if (event.type == SDL_QUIT) {}
//    //    }
//    //}
//}
//
//void GameLauncher::Update()
//{
//
//}
//
//void GameLauncher::Run(SDLWindow& sdlContext, GameLauncher& game, int frame_rate)
//{
//    Uint32 before, second = SDL_GetTicks(), after;
//    int frame_time, frames = 0;
//
//    while (true)
//    {
//        before = SDL_GetTicks();
//
//        bool quit = false;
//        PollEvents(sdlContext, quit);
//
//        if (quit)
//            break;
//
//        game.Update();
//
//        Render(sdlContext, game);
//
//        frames++;
//        after = SDL_GetTicks();
//        frame_time = after - before;
//
//        if (after - second >= 1000)
//        {
//            frames = 0;
//            second = after;
//        }
//
//        if (frame_rate > frame_time)
//        {
//            SDL_Delay(frame_rate - frame_time);
//        }
//    }
//}