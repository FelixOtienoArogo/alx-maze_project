#include <SDL2/SDL.h>
#include "maze.h"
/**
 *poll_events - track events in maze
 *
 *Return: 0 -success and 1 fail
 */
int poll_events(void)
{
SDL_Event event;

while (SDL_PollEvent(&event))
{
if (event.type == SDL_QUIT)
{
return (1);
break;
}
/* if 'ESCAPE' is pressed */
if (keyDown(SDL_SCANCODE_ESCAPE))
{
return (1);
break;
}
}
return (0);
}
