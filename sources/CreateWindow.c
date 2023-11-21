#include <stdio.h>
#include <SDL2/SDL.h>

void createWindow() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Unable to initialize SDL: %s\n", SDL_GetError());
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow(
        "Moteur d'inférence",                   // Window title
        SDL_WINDOWPOS_CENTERED,         // X position
        SDL_WINDOWPOS_CENTERED,         // Y position
        640,                            // Width
        480,                            // Height
        SDL_WINDOW_SHOWN                // Flags
    );

    if (!window) {
        printf("Failed to create window: %s\n", SDL_GetError());
    }

    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        printf("Failed to create renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    // Set the renderer color to white
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // Clear the window with the renderer color
    SDL_RenderClear(renderer);

    // Update the screen
    SDL_RenderPresent(renderer);

    // Main loop
    int isRunning = 1;
    SDL_Event event;
    while (isRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isRunning = 0;
            }
        }
    }

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}