#include <SDL2/SDL.h>
#include "../headers/maze.h"
/**
 *background - draws the sky in the background
 *
 *@instance: the sdl instance
 *@SCREEN_HEIGHT: the height of the screen
 *@SCREEN_WIDTH: the width of the screen
 *
 *Return: 1 on success
 */

int background(SDL_Instance *instance, const int *SCREEN_HEIGHT,
	       const int *SCREEN_WIDTH)
{
SDL_Rect rect;
rect.x = 0;
rect.y = 0;
rect.w = *SCREEN_WIDTH;
rect.h = *SCREEN_HEIGHT / 2;

SDL_SetRenderDrawColor(instance->renderer, 0, 110, 230, 0xFF);

SDL_RenderFillRect(instance->renderer, &rect);

return (1);
}
