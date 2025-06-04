// GameLoop.hpp
#pragma once

#include <SDL3/SDL.h>

namespace BPE::Core {
    SDL_AppResult AppInit(void** appstate, int argc, char* argv[]);
    SDL_AppResult AppIterate(void* appstate);
    SDL_AppResult AppEvent(void* appstate, SDL_Event* event);
    void AppQuit(void* appstate, SDL_AppResult result);
}