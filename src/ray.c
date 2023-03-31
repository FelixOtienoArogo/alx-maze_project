#include <math.h>
#include <SDL2/SDL.h>
#include <stdio.h>
#include "../headers/maze.h"
/**
 *ray - draw the ray in minimap
 *
 *@hit: was a wall hit or not
 *@mac: is map activated or not
 *@instance: sdl instance
 *@posX: player position in x-axis
 *@posY: player position in y-axis
 *@mapY: positon of wall y-axis
 *@mapX: position of wall x-axis
 *
 *Return: nothing
 */
void ray(int hit, int *mac, SDL_Instance instance, double *posX,
	 double *posY, int mapY, int mapX)
{
if (hit == 0 && *mac == 1)
{
SDL_SetRenderDrawColor(instance.renderer, 255, 0, 0, 0xFF);
SDL_RenderDrawLine(instance.renderer, (int)(*posY) * 5, (int)(*posX) * 5,
		   mapY * 5, mapX * 5);
}
}
