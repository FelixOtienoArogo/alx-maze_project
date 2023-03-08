#include <math.h>
#include <stdbool.h>
#include "maze.h"
/**
 *motion - enable player move where there is no
 *
 *
 *Return: nothing
 */
void motion(int (*worldMap)[24], double *posX, double *posY, double *dirX,
	    double *dirY, double *planeX, double *planeY)
{
double moveSpeed = 0.1;
double rotSpeed = 0.01;
poll_events();
/*move forward if no wall in front of you*/
if (keyDown(SDL_SCANCODE_UP))
{
if (worldMap[(int)(*posX + *dirX * moveSpeed)][(int)(*posY)] == 0)
  *posX += (*dirX * moveSpeed);
if (worldMap[(int)(*posX)][(int)(*posY - *dirY * moveSpeed)] == 0)
  *posY += (*dirY * moveSpeed);
}
/*move backwards if no wall behind you*/
 if (keyDown(SDL_SCANCODE_DOWN))
{
if (worldMap[(int)(*posX - *dirX * moveSpeed)][(int)(*posY)] == 0)
  *posX -= (*dirX * moveSpeed);
if (worldMap[(int)(*posX)][(int)(*posY - *dirY * moveSpeed)] == 0)
*posY -= *dirY * moveSpeed;
}
/*rotate to the right*/
if (keyDown(SDL_SCANCODE_RIGHT))
{
/*both camera direction and camera plane must be rotated*/
double oldDirX = *dirX;
*dirX = *dirX * (cos(-rotSpeed)) - *dirY * (sin(-rotSpeed));
*dirY = oldDirX * (sin(-rotSpeed)) + *dirY * (cos(-rotSpeed));
double oldPlaneX = *planeX;
*planeX = *planeX * (cos(-rotSpeed)) - *planeY * (sin(-rotSpeed));
*planeY = oldPlaneX * (sin(-rotSpeed)) + *planeY * (cos(-rotSpeed));
}
/*rotate to the left*/
 if (keyDown(SDL_SCANCODE_LEFT))
{
/*both camera direction and camera plane must be rotated*/
double oldDirX = *dirX;
*dirX = *dirX * (cos(rotSpeed)) - *dirY * (sin(rotSpeed));
*dirY = oldDirX * (sin(rotSpeed)) + *dirY * (cos(rotSpeed));
double oldPlaneX = *planeX;
*planeX = *planeX * (cos(rotSpeed)) - *planeY * (sin(rotSpeed));
*planeY = oldPlaneX * (sin(rotSpeed)) + *planeY * (cos(rotSpeed));
}
}
