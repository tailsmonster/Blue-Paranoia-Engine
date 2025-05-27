#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

struct Player {
  float x, y;
  float w, h;
  float speed;
};

static Player player = { 200, 100, 32, 32, 150.0f };


SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
    SDL_SetAppMetadata("Blue Paranoia Game Engine", "0.0.01", "com.blueparanoia.engine");

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (SDL_CreateWindowAndRenderer("Blue Paranoia", 424, 240, 0, &window, &renderer) < 0) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    }
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate)
{
    // Get time delta in seconds
    static uint64_t last_ticks = 0;
    uint64_t current_ticks = SDL_GetTicks();
    float dt = (last_ticks == 0) ? 0 : (current_ticks - last_ticks) / 1000.0f;
    last_ticks = current_ticks;

    // SDL3: keyboard state is const bool*
    const bool *keys = SDL_GetKeyboardState(NULL);

    // Move player rectangle with arrow keys
    if (keys[SDL_SCANCODE_LEFT])  player.x -= player.speed * dt;
    if (keys[SDL_SCANCODE_RIGHT]) player.x += player.speed * dt;
    if (keys[SDL_SCANCODE_UP])    player.y -= player.speed * dt;
    if (keys[SDL_SCANCODE_DOWN])  player.y += player.speed * dt;

    // Clamp player inside window bounds
    if (player.x < 0) player.x = 0;
    if (player.y < 0) player.y = 0;
    if (player.x + player.w > 424) player.x = 424 - player.w;
    if (player.y + player.h > 240) player.y = 240 - player.h;

    // Clear screen (black)
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // SDL3: Use SDL_FRect (floats) instead of SDL_Rect (ints)
    SDL_FRect rect = { player.x, player.y, player.w, player.h };
    SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderPresent(renderer);

    return SDL_APP_CONTINUE;
}



void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    /* SDL cleans up window/renderer automatically */
}
