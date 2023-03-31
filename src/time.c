#include <stdio.h>
#include "../headers/maze.h"
/**
 *time - times the input
 *
 *
 *Return: nothing
 */
double time(void)
{
double time = 0; /*time of current frame*/
double oldTime = 0; /*time of previous frame*/

oldTime = time;
time = SDL_GetTicks();
double frameTime = (time - oldTime) / 1000.0; /*time the frame has taken*/
printf("%f/n", 1.0 / frameTime);

return (frameTime);
}
