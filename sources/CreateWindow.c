#include <stdio.h>
#include <CreateWindw.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

void printImageToScreen(SDL_Window *window, SDL_Renderer *renderer, SDL_Surface *image, unsigned short x, unsigned short y, unsigned short w, unsigned short h){
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_Rect dstrect = { x, y, w, h };
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);
}

void printButtonOnScreen(SDL_Window *window, SDL_Renderer *renderer, char* str, unsigned short x, unsigned short y, unsigned short w, unsigned short h){
    TTF_Init();
    printImageToScreen(window, renderer, SDL_LoadBMP("./assets/josh_hutcherson_whistle.bmp"), x, y, w, h);
    TTF_Font* font = TTF_OpenFont("./assets/OpenSans-Regular.ttf", 25 );
    SDL_Color textColor = { 0, 0, 0 };
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, str, textColor);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    int textWidth = textSurface->w;
    int textHeight = textSurface->h;
    int textX = x + (w - textWidth) / 2;
    int textY = y + (h - textHeight) / 2;
    SDL_Rect textRect = { textX, textY, textWidth, textHeight };
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
    TTF_CloseFont(font);
}

int isMouseInsideButton(int mouseX, int mouseY, unsigned short x, unsigned short y, unsigned short w, unsigned short h) {
    return (mouseX >= x && mouseX <= x + w && mouseY >= y && mouseY <= y + h);
}

void handleButtonClick(SDL_Event *event, int *clickedButton, int *buttonClicked, Button *buttons) {
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    if (event->type == SDL_MOUSEBUTTONDOWN) {
        *buttonClicked = -1;
        for (int i = 0; i < *clickedButton; ++i) {
            if (isMouseInsideButton(mouseX, mouseY, buttons[i].x, buttons[i].y, buttons[i].w, buttons[i].h)) {
                *buttonClicked = i;
                break;
            }
        }
    }
}


void printDropdownOnScreen(SDL_Window *windows, SDL_Renderer *renderer, char* str, unsigned short x, unsigned short y, unsigned short w, unsigned short h){

}

void printTextOnScreen(SDL_Window *window, SDL_Renderer *renderer, char* str, unsigned short fontSize, unsigned short x, unsigned short y) {
    TTF_Init();
    TTF_Font *font = TTF_OpenFont("./assets/OpenSans-Regular.ttf", fontSize);
    SDL_Color color = {0, 0, 0, 255};
    SDL_Surface *surface = TTF_RenderText_Solid(font, str, color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect textRect;
    textRect.x = x;
    textRect.y = y;
    textRect.w = surface->w;
    textRect.h = surface->h;
    SDL_RenderCopy(renderer, texture, NULL, &textRect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
    TTF_CloseFont(font);
    TTF_Quit();
}

void createWindow() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Unable to initialize SDL: %s\n", SDL_GetError());
    }
    // Create a window
    SDL_Window* window = SDL_CreateWindow(
        "Moteur d'inférence",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        640,
        480,
        SDL_WINDOW_SHOWN
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

    Button buttons[5];
    buttons[0] = (Button){100, 50, 200, 50, "Button 1"};
    buttons[1] = (Button){100, 150, 200, 50, "Button 2"};
    buttons[2] = (Button){100, 250, 200, 50, "Button 3"};
    buttons[3] = (Button){100, 350, 200, 50, "Button 4"};
    buttons[4] = (Button){100, 450, 200, 50, "Button 5"};
    int clickedButton = 5;
    int buttonClicked = -1;


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
            handleButtonClick(&event, &clickedButton, &buttonClicked, buttons);
        }
        for (int i = 0; i < clickedButton; ++i) {
            printButtonOnScreen(window, renderer, buttons[i].label, buttons[i].x, buttons[i].y, buttons[i].w, buttons[i].h);
        }
        if (buttonClicked != -1) {
            printf("Button %d clicked!\n", buttonClicked + 1);
            buttonClicked = -1;
        }
        SDL_RenderPresent(renderer);
    }

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}