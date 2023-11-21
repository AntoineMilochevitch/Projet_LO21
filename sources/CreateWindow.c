#include <stdio.h>
#include <CreateWindw.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

void printTextOnScreen(SDL_Window *window, SDL_Renderer *renderer, char* str, unsigned short x, unsigned short y) {
    TTF_Init();
    int totalHeight = 0;

    for (int i = 0; i < 10; i++) {
        TTF_Font *font = TTF_OpenFont("./assets/OpenSans-Regular.ttf", i * 9);
        SDL_Color color = {0, 0, 0, 255};
        SDL_Surface *surface = TTF_RenderText_Solid(font, str, color);
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_Rect textRect;
        textRect.x = x;
        textRect.y = y + totalHeight; // Use totalHeight instead of surface->h * 2
        textRect.w = surface->w;
        textRect.h = surface->h;

        SDL_RenderCopy(renderer, texture, NULL, &textRect);

        totalHeight += surface->h; // Update total height
        totalHeight += 5; // Add some extra space between lines (adjust as needed)

        SDL_DestroyTexture(texture);
        SDL_FreeSurface(surface);
        TTF_CloseFont(font);
    }
    TTF_Quit();
}

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

    printTextOnScreen(window, renderer, "Hello World", 0, 0);
    // Update the screen
    SDL_RenderPresent(renderer);


    // Main loop
    unsigned short isRunning = 1;
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