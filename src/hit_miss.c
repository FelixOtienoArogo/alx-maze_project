/**
 *hitMiss - check if there is a hit or a miss
 *
 *@parameter: the parameter required
 *
 *Return: a hit or a miss
 */
int hitMiss(double *rayDirX, double *rayDirY, double *posX, double *posY,
	    int *mapX, int *mapY, double *deltaDistX, double *deltaDistY,
	    double *sideDistX, double *sideDistY, int hit, char **worldMap)
{
/*what direction to step in x or y direction*/
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
/*perform DDA*/
while (hit == 0)
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
