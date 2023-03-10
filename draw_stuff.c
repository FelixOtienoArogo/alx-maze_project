#include <SDL2/SDL.h>
#include "maze.h"
/**
 *draw_stuff - draws a line
 *
 *@instance: the sdl instance
 *
 *Return: nothing
 */

int draw_stuff(SDL_Instance *instance, int *drawStart, int *drawEnd,
		int x, const int *SCREEN_HEIGHT, const int *SCREEN_WIDTH)
{
int y1 = *drawStart;
int y2 = *drawEnd;
int y;
if(y2 < y1)
{
y1 += y2;
y2 = y1 - y2;
y1 -= y2;
}/*swap y1 and y2*/
if(y2 < 0 || y1 >= *SCREEN_HEIGHT  || x < 0 || x >= *SCREEN_WIDTH)
return 0;/*no single point of the line is on screen*/
if(y1 < 0)
y1 = 0; /*clip*/
if(y2 >= *SCREEN_WIDTH)
y2 = *SCREEN_HEIGHT - 1; /*clip*/
SDL_SetRenderDrawColor(instance->renderer, 128, 128, 128, 0xFF);
for (y = y1; y <= y2; y++)
{
SDL_RenderDrawLine(instance->renderer, x, y1, x, y2);
}
return (1);
}
