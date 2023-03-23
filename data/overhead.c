#include "../headers/maze.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
/**
 *main - to draw the overhead map
 *
 *
 *
 */
int main(void)
{
/*The boundaries of the window*/
SDL_Instance instance;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
double posX = 22, posY = 22;  /*x and y start position*/

 int i, j, mac = 0;
SDL_Rect miniMap;
map(&instance);
char **worldMap = instance.worldMap;
miniMap.x = 0;
miniMap.y = 0;
miniMap.w = 5;
miniMap.h = 5;

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
SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
SDL_RenderDrawLine(instance.renderer, 10,10, 100, 100);
if(mac == 1)
{
for(i = 0; i < 24; i++)
{
for(j = 0; j < 24; j++)
{
miniMap.x = j * 5;
miniMap.y = i * 5;
  if (worldMap[i][j] > '0')
   SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0xFF);
  else
   SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderFillRect(instance.renderer, &miniMap);
  SDL_SetRenderDrawColor(instance.renderer,255,255,0,0xFF);
  if (i < 80 && worldMap[i][j] > '0')
    {SDL_RenderDrawLine(instance.renderer, posX * 5, posY * 5, i, j);}
}}
 }
 
SDL_RenderPresent(instance.renderer);
}
/*Free resources and close SDL*/
SDL_DestroyRenderer(instance.renderer);
SDL_DestroyWindow(instance.window);
SDL_Quit();
free_map(worldMap);

return(0);
}
