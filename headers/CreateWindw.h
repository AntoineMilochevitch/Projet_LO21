#ifndef __CREATEWINDOW__H__
#define __CREATEWINDOW__H__

#include "../headers/rules.h"
#include "../headers/knowledge_base.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef struct dE{
    char* textOnScreen;
    struct dE *next;
} DropDownItem;

typedef struct dropdown{
    char* textDisplayed;
    unsigned short nbElements;
    struct dE *head;
} DropDown;

void createWindow();
void printTextOnScreen(SDL_Window *window, SDL_Renderer *renderer, char*, unsigned short fontSize, unsigned short x, unsigned short y);
void printButtonOnScreen(SDL_Window *window, SDL_Renderer *renderer, char* str, unsigned short x, unsigned short y, unsigned short w, unsigned short h);
void printDropdownOnScreen(SDL_Window *windows, SDL_Renderer *renderer, char* str, unsigned short x, unsigned short y, unsigned short w, unsigned short h);
void printImageToScreen(SDL_Window *window, SDL_Renderer *renderer, SDL_Surface *image, unsigned short x, unsigned short y, unsigned short w, unsigned short h);

#endif