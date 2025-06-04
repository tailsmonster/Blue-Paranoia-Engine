// Event.hpp
#pragma once
#include <SDL3/SDL.h>

namespace BPE::Core {
    SDL_AppResult HandleEvent(void* state, SDL_Event* event);
}
