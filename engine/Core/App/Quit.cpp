// Quit.cpp
#include <SDL3/SDL.h>
#include "Quit.hpp"

namespace BPE::Core {

  void Shutdown(void* state, SDL_AppResult result) {
      SDL_Log("Shutting down Blue Paranoia Engine");
      SDL_Quit();
  }

}
