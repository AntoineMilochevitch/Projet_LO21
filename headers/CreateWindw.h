#ifndef __CREATEWINDOW__H__
#define __CREATEWINDOW__H__

#include "../headers/rules.h"
#include "../headers/knowledge_base.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

void createWindow();
void printTextOnScreen(SDL_Window *window, SDL_Renderer *renderer, char*, unsigned short fontSize, unsigned short x, unsigned short y);

#endif