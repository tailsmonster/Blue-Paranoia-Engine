#include "engine/GameLoop.hpp"
#include "SDL3/SDL.h"
#include "SDL3/SDL_main.h"

namespace blueparanoia {
  static SDL_Window *window = NULL;
  static SDL_Renderer *renderer = NULL;

  static GameCallbacks callbacks;

  SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[]) {
    SDL_SetAppMetadata("Blue Paranoia Game Engine", "0.0.01", "https://github.com/tailsmonster/BlueParanoiaEngine");

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
      SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
      return SDL_APP_FAILURE;
    }

    if (SDL_CreateWindowAndRenderer("Blue Paranoia", 1000, 600, 0, &window, &renderer) < 0) {
      SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
      return SDL_APP_FAILURE;
    }

    if (callbacks.init) {
      callbacks.init();
    }

    return SDL_APP_CONTINUE;
  }

  SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event) {
    if (event->type == SDL_EVENT_QUIT) {
      return SDL_APP_SUCCESS;
    }

    if (callbacks.handleEvent) {
      callbacks.handleEvent(*event);
    }

    return SDL_APP_CONTINUE;
  }

  SDL_AppResult SDL_AppIterate(void* appstate) {
    static uint64_t last_ticks = 0;
    uint64_t current_ticks = SDL_GetTicks();
    float dt = (last_ticks == 0) ? 0 : (current_ticks - last_ticks) / 1000.0f;
    last_ticks = current_ticks;

    if (callbacks.update) {
      callbacks.update(dt);
    }

    if (callbacks.render) {
      callbacks.render(renderer);
    }

    return SDL_APP_CONTINUE;
  }

  void SDL_AppQuit(void* appstate, SDL_AppResult result) {
    if (callbacks.shutdown) {
      callbacks.shutdown();
    }
    SDL_Quit();
  }

  int RunGame(const GameCallbacks& gameCallbacks) {
    callbacks = gameCallbacks;
    return SDL_RunApp(NULL, SDL_AppInit, SDL_AppEvent, SDL_AppIterate, SDL_AppQuit);
  }

}