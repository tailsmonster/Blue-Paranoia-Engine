// Init.cpp
#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include "Init.hpp"
// #include "../Metadata.hpp"

namespace BPE::Core {

SDL_AppResult Init(void** state, int argc, char* argv[]) {
    SDL_SetAppMetadata("Blue Paranoia", "0.0.01", "com.blueparanoia.engine");

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL_Init failed: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    SDL_Window* window = SDL_CreateWindow("BlueParanoia", 424, 240, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, "BlueParanoia");

    if (!window || !renderer) {
        SDL_Log("Window or renderer creation failed: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    // TODO: Store window/renderer in *state later when you make an app state struct
    return SDL_APP_CONTINUE;
}

}
