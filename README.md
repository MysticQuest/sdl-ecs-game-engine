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

The engine handles the low level parts of the gameloop (frames, rendering, system update, polling etc), and is also agnostically observed by the game's update, intended for game-specific logic. 

### Supported Components
- Rendering
- Input
- Transform
- Collision
