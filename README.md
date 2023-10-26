# Breeze engine (WIP)
A simple ECS game engine using SDL.

This repo contains a VS solution made of two projects.
- A game engine (library build dependency for the game).
- A game (windows application).

When the engine project is built, its DLL, any SDL runtime dependencies, a res folder containing the textures,  and an engine.ini file containing settings, get copied to the game's binaries path.

### Entity Component System
- Entities work as plain identifiers and are mapped to components.
- Components are simple data structs, devoid of behaviour.
- Systems manage the components' behaviour and logic.

### Supported Components
- Rendering
- Input
- Transform
- Collision

### Notes
- The engine loop handles low level runtime functions (frames, rendering, system update, event polling etc).
- The engine loop is agnostically observed by the game's update, intended for game-specific logic.
- At the moment, the game reads the engine.ini and loads the textures inside the res folder.

## Sample Game
![image](https://github.com/MysticQuest/sdl-ecs-game-engine/assets/9077026/60f4e832-c74d-4d33-a827-0e9c5b3b2091)
