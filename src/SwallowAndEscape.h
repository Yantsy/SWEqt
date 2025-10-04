#pragma once
#include <SDL2/SDL.h>
#define SWALLOW_AND_ESCAPE_H
void keyboard(int *xdir, int *ydir, SDL_Event e);
void boundarycheck(SDL_Rect *object, SDL_Rect map);