#include "../headers/maze.h"
#include <stdbool.h>
/**
 *keyDown - gives value of pressed key to inkeys.
 *
 *@key: the key pressed
 *
 *Return: the key pressed
 */
int keyDown(int key)
{
SDL_PumpEvents();
const Uint8 *inkeys = SDL_GetKeyboardState(NULL);
if (!inkeys)
return (false);
return (inkeys[key] != 0);
}
