// Event.cpp
#include <SDL3/SDL.h>
#include "Event.hpp"

namespace BPE::Core {

SDL_AppResult HandleEvent(void* state, SDL_Event* event) {
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    }
    return SDL_APP_CONTINUE;
}

}
