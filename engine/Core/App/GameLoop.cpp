// GameLoop.cpp
#include "GameLoop.hpp"

#include "Init.hpp"
#include "Iterate.hpp"
#include "Event.hpp"
#include "Quit.hpp"

namespace BPE::Core {
    SDL_AppResult AppInit(void** state, int argc, char* argv[])    { return Init(state, argc, argv); }
    SDL_AppResult AppIterate(void* state)                          { return Iterate(state); }
    SDL_AppResult AppEvent(void* state, SDL_Event* evt)            { return HandleEvent(state, evt); }
    void          AppQuit(void* state, SDL_AppResult result)       { return Shutdown(state, result); }
}
