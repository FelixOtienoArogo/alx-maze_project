#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include "../headers/maze.h"
/**
 *motion - enable player move where there is no wall
 *
 *@worldMap: the map of play area
 *@posX: player position in x direction
 *@posY: player postion in y direction
 *@dirX: player direction x-axis
 *@dirY: player direction y-axis
 *@planeX: camera plane in x-axis
 *@planeY: camera plane in y-axis
 *
 *Return: nothing
 */
void motion(char **worldMap, double *posX, double *posY, double *dirX,
	    double *dirY, double *planeX, double *planeY)
{
double moveSpeed = 0.0003;
double rotSpeed = 0.0002;
poll_events();
/*move forward if no wall in front of you*/
if (keyDown(SDL_SCANCODE_UP))
{
if (worldMap[(int)(*posX + (*dirX * moveSpeed))][(int)(*posY)] == '0')
*posX += (*dirX * moveSpeed);
if (worldMap[(int)(*posX)][(int)(*posY + (*dirY * moveSpeed))] == '0')
*posY += (*dirY * moveSpeed);
}
/*move backwards if no wall behind you*/
if (keyDown(SDL_SCANCODE_DOWN))
{
if (worldMap[(int)(*posX - (*dirX * moveSpeed))][(int)(*posY)] == '0')
*posX -= (*dirX * moveSpeed);
if (worldMap[(int)(*posX)][(int)(*posY - (*dirY * moveSpeed))] == '0')
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
if (keyDown(SDL_SCANCODE_LEFT)) /*rotate to the left*/
{
/*both camera direction and camera plane must be rotated*/
double oldDirX = *dirX;
*dirX = *dirX * (cos(rotSpeed)) - *dirY * (sin(rotSpeed));
*dirY = oldDirX * (sin(rotSpeed)) + *dirY * (cos(rotSpeed));
double oldPlaneX = *planeX;
*planeX = *planeX * (cos(rotSpeed)) - *planeY * (sin(rotSpeed));
*planeY = oldPlaneX * (sin(rotSpeed)) + *planeY * (cos(rotSpeed));
}}
