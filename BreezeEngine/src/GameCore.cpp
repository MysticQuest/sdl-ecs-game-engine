#include <memory>
#include <random>
#include "GameCore.h"
#include "Utils.h"

GameCore::GameCore(MySDLWindow& sdlWindow, int frame_rate)
    : m_sdlWindow(sdlWindow), m_frame_rate(frame_rate), isRunning(true)
{
    InitializeGame();
}

void GameCore::InitializeGame()
{
    ecs = ECSManager();
    renderSystem = std::make_unique<RenderSystem>(m_sdlWindow.GetRenderer());
    collisionSystem = std::make_unique<CollisionSystem>(m_sdlWindow.GetRenderer());
    gameOver = false;
}

GameCore::~GameCore() { }

void GameCore::PollEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    if (keystates[SDL_SCANCODE_ESCAPE] || event.type == SDL_QUIT)
    {
        isRunning = false;
    }

    if (gameOver && event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_r) 
    {
        RestartGame();
        SDL_DestroyTexture(gameOverTexture);
    }

    if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_SPACE)
    {
        eventObserver(SpaceReleased);
    }

    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_q) 
    {
        GameOver();
    }
}

void GameCore::RegisterObserver(const std::function<void(int)>& callback) 
{
    updateObserver = callback;
}

void GameCore::RegisterEventObserver(const std::function<void(int)>& callback) 
{
    eventObserver = callback;
}

void GameCore::GameOver() {
    gameOver = true;
    SDL_Renderer* renderer = m_sdlWindow.GetRenderer();
    gameOverTexture = IMG_LoadTexture(m_sdlWindow.GetRenderer(), "res/textures/gameover.png");
}

void GameCore::RestartGame() 
{
    InitializeGame();
}

void GameCore::Render(MySDLWindow& sdlWindow, const std::vector<Entity>& entities)
{
    sdlWindow.Clear();
    sdlWindow.Render(ecs);

    if (gameOver) {
        Vector2 windowSizeI = utils::GetWindowSize();
        int width, height;
        SDL_QueryTexture(gameOverTexture, NULL, NULL, &width, &height);
        SDL_Rect renderQuad = {
            (windowSizeI.X - width) / 2,  // Centered x
            (windowSizeI.Y - height) / 2, // Centered y
            width,
            height
        };
        SDL_RenderCopy(sdlWindow.GetRenderer(), gameOverTexture, nullptr, &renderQuad);
    }

    sdlWindow.Display();
}

void GameCore::Update(int deltaTime)
{
    if (!gameOver)
    {
        renderSystem->Update(ecs);
        transformSystem->Update(ecs, deltaTime);
        inputSystem->Update(ecs);
        collisionSystem->Update(ecs);

        if (updateObserver) {
            updateObserver(deltaTime);
        }
    }
}

void GameCore::Run(MySDLWindow& sdlWindow)
{
    Uint32 before, second = SDL_GetTicks(), after;
    int deltaTime = 0;
    int frames = 0;

    while (isRunning)
    {
        before = SDL_GetTicks();

        PollEvents();

        Update(deltaTime);

        Render(sdlWindow, entities);
        
        frames++;
        after = SDL_GetTicks();
        deltaTime = after - before;

        if (after - second >= 1000)
        {
            frames = 0;
            second = after;
        }

        if (m_frame_rate > deltaTime)
        {
            SDL_Delay(m_frame_rate - deltaTime);
        }
    }
}

