// main.cpp
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "Core/App/GameLoop.hpp"

#ifdef USE_SDL_CALLBACKS

#define SDL_MAIN_USE_CALLBACKS 1

extern "C" SDL_AppResult SDL_AppInit(void **state, int argc, char *argv[]) {
    return BPE::Core::AppInit(state, argc, argv);
}

extern "C" SDL_AppResult SDL_AppIterate(void *state) {
    return BPE::Core::AppIterate(state);
}

extern "C" SDL_AppResult SDL_AppEvent(void *state, SDL_Event *event) {
    return BPE::Core::AppEvent(state, event);
}

extern "C" void SDL_AppQuit(void *state, SDL_AppResult result) {
    BPE::Core::AppQuit(state, result);
}

#else

int main(int argc, char* argv[]) {
    return SDL_EnterAppMainCallbacks(argc, argv,
        BPE::Core::AppInit,
        BPE::Core::AppIterate,
        BPE::Core::AppEvent,
        BPE::Core::AppQuit
    );
}

#endif
