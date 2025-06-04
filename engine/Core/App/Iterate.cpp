// Iterate.cpp
#include <SDL3/SDL.h>
#include "Iterate.hpp"

namespace BPE::Core {

SDL_AppResult Iterate(void* state) {
    SDL_Renderer* renderer = SDL_GetRenderer(*(SDL_GetWindows(0))); // temporary
    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    return SDL_APP_CONTINUE;
}

}
