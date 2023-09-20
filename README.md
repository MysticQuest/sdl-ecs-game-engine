# Breeze engine (WIP)
A simple ECS game engine using SDL.

This repo contains a VS solution made of two (as of yet) distinct projects.
- An engine (.dll project) dependency.
- A sample game (windows application).

### Entity Component System
- Entities work as plain identifiers and are mapped to components.
- Components are simple data structs, devoid of behaviour.
- Systems manage the components' behaviour and logic.

### Supported Components
- Rendering
- Input
- Transform
- Collision (WIP)
