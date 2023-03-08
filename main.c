/**
 * main - Entry point
 *
 * Return: 0 for success
 */
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "maze.h"

int main(void)
{
/*The boundaries of the window*/
SDL_Instance instance;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
double posX = 22, posY = 12;  /*x and y start position*/
double dirX = -1, dirY = 0; /*initial direction vector*/
double planeX = 0, planeY = 0.66; /*the 2d raycaster version of camera plane*/
map(&instance);
int (*worldMap)[24] = instance.worldMap;
if (init(&instance, SCREEN_WIDTH, SCREEN_HEIGHT) != 0)
{
return (1);
}
while (poll_events() != 1)
{
SDL_SetRenderDrawColor(instance.renderer, 0, 128, 0, 0);
SDL_RenderClear(instance.renderer);
/*
 *Draw some stuff here
 */
position(worldMap, &SCREEN_WIDTH, &SCREEN_HEIGHT, instance, &posX, &posY, &dirX, &dirY, &planeX, &planeY);
}
/*Free resources and close SDL*/
SDL_DestroyRenderer(instance.renderer);
SDL_DestroyWindow(instance.window);
SDL_Quit();
if (worldMap[0][0] > 0)
printf(" ");
return (0);
}
