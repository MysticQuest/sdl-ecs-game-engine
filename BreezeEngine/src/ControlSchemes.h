#pragma once

constexpr int ACTION_UP = 0;
constexpr int ACTION_DOWN = 1;
constexpr int ACTION_LEFT = 2;
constexpr int ACTION_RIGHT = 3;

constexpr int CONTROL_SCHEME_X = (1 << ACTION_LEFT) | (1 << ACTION_RIGHT);
constexpr int CONTROL_SCHEME_Y = (1 << ACTION_UP) | (1 << ACTION_DOWN);
constexpr int CONTROL_SCHEME_XY = CONTROL_SCHEME_X | CONTROL_SCHEME_Y;
