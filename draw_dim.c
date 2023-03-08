#include "maze.h"
/**
 *drawDim - changes dimensions of line to be drawn
 *
 *
 *Return: nothing
 */
void drawDim(int *drawStart, int *drawEnd, double *perpWallDist,
	     const int *SCREEN_HEIGHT)
{
/*Calculate height of line to draw onthe screen*/
int lineHeight = (int)(*SCREEN_HEIGHT / *perpWallDist);
/*Calculate lowest and highest pixel to fill in current stripe*/
*drawStart = -lineHeight / 2 + *SCREEN_HEIGHT / 2;
if (*drawStart < 0)
{
*drawStart = 0;
}
*drawEnd = lineHeight / 2 + *SCREEN_HEIGHT / 2;
if (*drawEnd >= *SCREEN_HEIGHT)
*drawEnd = *SCREEN_HEIGHT - 1;
}
