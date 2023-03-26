/**
 *hitMiss - check if there is a hit or a miss
 *
 *@rayDirX: the direction of ray in x axis
 *@rayDirY: the direction of ray in y axis
 *@posX: player position in x axis
 *@posY: player position in y axis
 *@mapX: x-index in map
 *@mapY: y-index in map
 *@deltaDistX: const
 *@deltaDistY: const
 *@sideDistX: distance to side in x-axis
 *@sideDistY: distance ot side in y-axis
 *@hit: is a wall hit or not
 *@worldMap: the map of the play area
 *
 *Return: a hit or a miss
 */
int hitMiss(double *rayDirX, double *rayDirY, double *posX, double *posY,
	    int *mapX, int *mapY, double *deltaDistX, double *deltaDistY,
	    double *sideDistX, double *sideDistY, int hit, char **worldMap)
{ /*what direction to step in x or y direction*/
int stepX, stepY, side; /*was a NS or a EW wall hit*/
/*calculate step and initial sideDist*/
if (*rayDirX < 0)
{
stepX = -1;
*sideDistX = (*posX - *mapX) * (*deltaDistX);
}
else
{
stepX = 1;
*sideDistX = (*mapX + 1.0 - *posX) * (*deltaDistX);
}
if (*rayDirY < 0)
{
stepY = -1;
*sideDistY = (*posY - *mapY) * (*deltaDistY);
}
else
{
stepY = 1;
*sideDistY = (*mapY + 1.0 - *posY) * (*deltaDistY);
}
while (hit == 0) /*perform DDA*/
{
if (*sideDistX < *sideDistY)
{
*sideDistX += *deltaDistX;
*mapX += stepX;
side = 0;
}
else
{
*sideDistY += *deltaDistY;
*mapY += stepY;
side = 1;
}
if ((worldMap[*mapX][*mapY]) > '0')
hit = 1;
}
return (side);
}
