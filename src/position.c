#include <math.h>
#include <SDL2/SDL.h>
#include <stdio.h>
#include "../headers/maze.h"
/**
 *position- calculates ray positions and directions
 *
 *@worldMap: map of play area
 *@SCREEN_WIDTH: width of the screen
 *@SCREEN_HEIGHT: height of the screen
 *@instance: the sdl instance
 *@posX: player posititon in x-axis
 *@posY: player position in y-axis
 *@dirX: player direction in x-axis
 *@dirY: player direction in y-axis
 *@planeX: camera plane in x-axis
 *@planeY: camera plane in y-axis
 *@mac: map activated or not
 *
 *Return: nothing
 */

void position(char **worldMap, const int *SCREEN_WIDTH,
	      const int *SCREEN_HEIGHT, SDL_Instance instance,
	      double *posX, double *posY, double *dirX, double *dirY,
	      double *planeX, double *planeY, int *mac)
{
int x = 0, drawStart = 0, drawEnd = 0;

if (*mac == 1)
miniMap(&instance);

for (x = *SCREEN_WIDTH; x--;)
{
double cameraX = 2 * x / (double)*SCREEN_WIDTH - 1;
double rayDirX = (*dirX) + (*planeX) * cameraX;
double rayDirY = (*dirY) + (*planeY) * cameraX;
/*the box we are in*/
int mapX = (int)(*posX), mapY = (int)(*posY);
double perpWallDist = 0, sideDistX = 0, sideDistY = 0;
/*lenght of ray from one x or y-side to next x or y-side*/
double deltaDistX = (rayDirX == 0) ? 1e30 : (double)(fabs(1 / rayDirX));
double deltaDistY = (rayDirY == 0) ? 1e30 : (double)(fabs(1 / rayDirY));
int hit = 0; /*was a wall hit*/
int side = hitMiss(&rayDirX, &rayDirY, posX, posY, &mapX, &mapY,
		   &deltaDistX, &deltaDistY, &sideDistX, &sideDistY, hit, worldMap);
if (side == 0)
perpWallDist = (sideDistX - deltaDistX);
else
perpWallDist = (sideDistY - deltaDistY);
drawDim(&drawStart, &drawEnd, &perpWallDist, SCREEN_HEIGHT);
draw_stuff(&instance, &drawStart, &drawEnd, x, SCREEN_HEIGHT,
	   SCREEN_WIDTH, side);
motion(worldMap, posX, posY, dirX, dirY, planeX, planeY);

ray(hit, mac, instance, posX, posY, mapY, mapX);
}
}
