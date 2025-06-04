#pragma once

#include <SDL3/SDL.h>

namespace blueparanoia {

    struct GameCallbacks {
        void (*init)() = nullptr;
        void (*update)(float dt) = nullptr;
        void (*render)(SDL_Renderer* renderer) = nullptr;
        void (*handleEvent)(SDL_Event& event) = nullptr;
        void (*shutdown)() = nullptr;
    };

    int RunGame(const GameCallbacks& gameCallbacks);

}