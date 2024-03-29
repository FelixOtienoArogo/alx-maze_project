#include "../headers/maze.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
/**
 *miniMap - draws the overhead map
 *
 *@instance: the sdl instance
 *
 *Return nothing
 */
void miniMap(SDL_Instance *instance)
{
char **worldMap = instance->worldMap;
SDL_Rect miniMap;
int i, j;
miniMap.x = 0;
miniMap.y = 0;
miniMap.w = 5;
miniMap.h = 5;

for (i = 0; i < 24; i++)
{
for (j = 0; j < 24; j++)
{
miniMap.x = j * 5;
miniMap.y = i * 5;
if (worldMap[i][j] > '0')
SDL_SetRenderDrawColor(instance->renderer, 0, 0, 0, 0);
else
SDL_SetRenderDrawColor(instance->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
SDL_RenderFillRect(instance->renderer, &miniMap);
}}
}
