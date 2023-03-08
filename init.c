/**
 *init - Starts up SDL and creates window
 *
 *@SCREEN_WIDTH: the width of the window created
 *@SCREEN_HEIGHT: the height of the window created
 *
 *Return: success or failure
 */

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "maze.h"

int init(SDL_Instance *instance, const int SCREEN_WIDTH,
	 const int SCREEN_HEIGHT)
{
/*initialisation flag*/
if (SDL_Init(SDL_INIT_VIDEO) != 0)
{
fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
return (1);
}
/*Create a new Window instance*/
instance->window = SDL_CreateWindow("The Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
if (instance->window == NULL)
{
fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
SDL_Quit();
return (1);
}
/*Create a new Renderer instance linked to the window */
instance->renderer = SDL_CreateRenderer(instance->window,-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
if (instance->renderer == NULL)
{
SDL_DestroyWindow(instance->window);
printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
SDL_Quit();
return (1);
}
return (0);
}
