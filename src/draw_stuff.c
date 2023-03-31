#include <SDL2/SDL.h>
#include "../headers/maze.h"
/**
 *draw_stuff - draws the walls of the playground
 *
 *@instance: the sdl instance
 *@drawStart: where to start drawing
 *@drawEnd: where to end drawing
 *@SCREEN_HEIGHT: The height of the screen
 *@SCREEN_WIDTH: the width of the surface
 *@side: check which side the wall is facing
 *@x: counter
 *
 *Return: 1 on success
 */

int draw_stuff(SDL_Instance *instance, int *drawStart, int *drawEnd,
	       int x, const int *SCREEN_HEIGHT, const int *SCREEN_WIDTH, int side)
{
int y1 = *drawStart;
int y2 = *drawEnd;
int y;
if (y2 < y1)
{
y1 += y2;
y2 = y1 - y2;
y1 -= y2;
} /*swap y1 and y2*/
if (y2 < 0 || y1 >= *SCREEN_HEIGHT  || x < 0 || x >= *SCREEN_WIDTH)
return (0);/*no single point of the line is on screen*/
if (y1 < 0)
y1 = 0; /*clip*/
if (y2 >= *SCREEN_WIDTH)
y2 = *SCREEN_HEIGHT - 1; /*clip*/
if (side == 0)
SDL_SetRenderDrawColor(instance->renderer, 110, 128, 128, 0xFF);
else
SDL_SetRenderDrawColor(instance->renderer, 128, 128, 128, 0xFF);
for (y = y1; y <= y2; y++)
{
SDL_RenderDrawLine(instance->renderer, x, y1, x, y2);
}
return (1);
}
