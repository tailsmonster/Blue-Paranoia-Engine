include "SDL3/sdl_main.h"
include "Gameloop.hpp"

#define SDL_MAIN_USE_CALLBACKS 1

int SDL_main(int argc, char *argv[]) {
    return SDL_EnterAppMainCallbacks(
        argc, 
        argv,
        BPE::Core::AppInit,
        BPE::Core::AppIterate,
        BPE::Core::AppEvent,
        BPE::Core::AppQuit
    );
}