#include <SDL3/SDL.h>
#include <iostream>

int main(int argc, char* argv[]) {

    SDL_Window *window;
    bool done = false;

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(
        "An SDL3 window",
        640,
        480,
        SDL_WINDOW_OPENGL
    );

    if(window == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);

    if(renderer == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create renderer: %s\n", SDL_GetError());
        return 1;
    }

    SDL_FRect player = { 100.0f, 100.0f, 50.0f, 50.0f};
    float speed = 200;

    Uint64 last_time = SDL_GetPerformanceCounter();

    while(!done) {
        Uint64 current_time = SDL_GetPerformanceCounter();
        
        double delta_time = (double) ((current_time - last_time) / (double)SDL_GetPerformanceFrequency());
        last_time = current_time;
        
        const bool *keys = SDL_GetKeyboardState(NULL);

        if(keys[SDL_SCANCODE_D]) {
            player.x += speed * delta_time;
        }
        if(keys[SDL_SCANCODE_S]) {
            player.y += speed * delta_time;
        }
        if(keys[SDL_SCANCODE_A]) {
            player.x -= speed * delta_time;
        }
        if(keys[SDL_SCANCODE_W]) {
            player.y -= speed * delta_time;
        }

        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                done = true;
            }
        }
        SDL_SetRenderDrawColor(renderer, 20, 20, 50, 255);
        SDL_RenderClear(renderer);
        
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &player);

        SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;

}