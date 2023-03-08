#include "maze.h"
#include <stdbool.h>
/**
 *readKeys - gives value of pressed key to inkeys.
 *
 *
 *Return: nothing
 */
int keyDown(int key)
{
SDL_PumpEvents();
const Uint8 *inkeys = SDL_GetKeyboardState(NULL);
if(!inkeys)
return false;
return(inkeys[key] != 0);
}
