#include "engine/GameLoop.hpp"
#include <SDL3/SDL.h>

// using namespace BPE;

struct Player {
  float x, y;
  float w, h;
  float speed;
};

static Player player = { 200, 100, 32, 32, 150.0f };


void Init() {
    // Any game-specific init
}

void Update(float dt) {
    const bool* keys = SDL_GetKeyboardState(NULL);

    if (keys[SDL_SCANCODE_LEFT])  player.x -= player.speed * dt;
    if (keys[SDL_SCANCODE_RIGHT]) player.x += player.speed * dt;
    if (keys[SDL_SCANCODE_UP])    player.y -= player.speed * dt;
    if (keys[SDL_SCANCODE_DOWN])  player.y += player.speed * dt;

    // Clamp to screen
    if (player.x < 0) player.x = 0;
    if (player.y < 0) player.y = 0;
    if (player.x + player.w > 424) player.x = 424 - player.w;
    if (player.y + player.h > 240) player.y = 240 - player.h;
}

void Render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_FRect rect = { player.x, player.y, player.w, player.h };
    SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderPresent(renderer);
}

int main(int argc, char* argv[]) {
    GameCallbacks callbacks = {
        .init = Init,
        .update = Update,
        .render = Render,
        .handleEvent = HandleEvent,
        .shutdown = Shutdown
    };

    return RunGame(callbacks);
}