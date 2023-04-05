/**
 * main - Entry point
 *
 * Return: 0 for success
 */
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "../headers/maze.h"

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
char **worldMap = instance.worldMap;
int mac = 0;

if (init(&instance, SCREEN_WIDTH, SCREEN_HEIGHT) != 0)
{
return (1);
}
while (poll_events() != 1)
{
SDL_SetRenderDrawColor(instance.renderer, 0, 128, 0, 0);
SDL_RenderClear(instance.renderer);
if (keyDown(SDL_SCANCODE_M) && mac == 0)
mac = 1;
else if (keyDown(SDL_SCANCODE_N) && mac == 1)
mac = 0;

/*
 *Draw some stuff here
 */
background(&instance, &SCREEN_HEIGHT, &SCREEN_WIDTH);
position(worldMap, &SCREEN_WIDTH, &SCREEN_HEIGHT, instance,
	 &posX, &posY, &dirX, &dirY, &planeX, &planeY, &mac);
SDL_RenderPresent(instance.renderer);
}
/*Free resources and close SDL*/
SDL_DestroyRenderer(instance.renderer);
SDL_DestroyWindow(instance.window);
SDL_Quit();
free_map(worldMap);
return (0);
}
