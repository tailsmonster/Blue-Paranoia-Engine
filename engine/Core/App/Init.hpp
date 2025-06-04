// Init.hpp
#pragma once
#include <SDL3/SDL.h>

namespace BPE::Core {
    SDL_AppResult Init(void** state, int argc, char* argv[]);
}
