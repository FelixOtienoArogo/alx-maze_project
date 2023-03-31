#include "../headers/maze.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
/**
 *main - to draw the overhead map
 *
 *
 *
 */
#define screenWidth 640
#define screenHeight 480
#define texWidth 64
#define texHeight 64
#define mapWidth 24
#define mapHeight 24

int main(void)
{
/*The boundaries of the window*/
SDL_Instance instance;
const int SCREEN_WIDTH = screenWidth;
const int SCREEN_HEIGHT = screenHeight;
double posX = 22.0, posY = 11.5;  /*x and y start position*/
double dirX = -1.0, dirY = 0.0; /*initial direction vector*/
double planeX = 0.0, planeY = 0.66; /*the 2d raycaster version of camera plane*/
 Uint32 buffer[screenHeight][screenWidth];
int mac = 0;
map(&instance);
char **worldMap = instance.worldMap;
int i;
Uint32 **texture;
texture = malloc(8 * sizeof(Uint32 *));
for(i = 0; i < 8; i++)
{
texture[i] = malloc(texWidth * texHeight * sizeof(Uint32));
}
if (init(&instance, SCREEN_WIDTH, SCREEN_HEIGHT) != 0)
{
return (1);
}
/*Generating textures*/
 int x; int y;
for(x = 0; x < texWidth; x++)
for(y = 0; y < texHeight; y++)
{
    int xorcolor = (x * 256 / texWidth) ^ (y * 256 / texHeight);
    //int xcolor = x * 256 / texWidth;
    int ycolor = y * 256 / texHeight;
    int xycolor = y * 128 / texHeight + x * 128 / texWidth;
    texture[0][texWidth * y + x] = 65536 * 254 * (x != y && x != texWidth - y); //flat red texture with black cross
    texture[1][texWidth * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
    texture[2][texWidth * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
    texture[3][texWidth * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
    texture[4][texWidth * y + x] = 256 * xorcolor; //xor green
    texture[5][texWidth * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
    texture[6][texWidth * y + x] = 65536 * ycolor; //red gradient
    texture[7][texWidth * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
  }

 
while (poll_events() != 1)
{
 for(int x = 0; x < SCREEN_WIDTH; x++)
    {
      //calculate ray position and direction                                                                                                                                                               
      double cameraX = 2 * x / (double)SCREEN_WIDTH - 1; //x-coordinate in camera space                                                                                                                               
      double rayDirX = dirX + planeX*cameraX;
      double rayDirY = dirY + planeY*cameraX;

      //which box of the map we're in                                                                                                                                                                      
      int mapX = (int)(posX);
      int mapY = (int)(posY);

      //length of ray from current position to next x or y-side                                                                                                                                            
      double sideDistX;
      double sideDistY;

      //length of ray from one x or y-side to next x or y-side                                                                                                                                             
      double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
      double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
      double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)                                                                                                                                       
      int stepX;
      int stepY;

      int hit = 0; //was there a wall hit?                                                                                                                                                                 
      int side; //was a NS or a EW wall hit?                                                                                                                                                               

      //calculate step and initial sideDist                                                                                                                                                                
      if(rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (posX - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - posX) * deltaDistX;
      }
      if(rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (posY - mapY) * deltaDistY;
      }
 else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - posY) * deltaDistY;
      }
      //perform DDA                                                                                                                                                                                        
      while (hit == 0)
      {
        //jump to next map square, either in x-direction, or in y-direction                                                                                                                                
        if(sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall                                                                                                                                                                      
        if(worldMap[mapX][mapY] > 0) hit = 1;
      }

      //Calculate distance of perpendicular ray (Euclidean distance would give fisheye effect!)                                                                                                            
      if(side == 0) perpWallDist = (sideDistX - deltaDistX);
      else          perpWallDist = (sideDistY - deltaDistY);

      //Calculate height of line to draw on screen                                                                                                                                                         
      int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);


      int pitch = 100;

      //calculate lowest and highest pixel to fill in current stripe                                                                                                                                       
      int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2 + pitch;
      if(drawStart < 0) drawStart = 0;
      int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2 + pitch;
      if(drawEnd >= SCREEN_HEIGHT) drawEnd = SCREEN_HEIGHT - 1;
 //texturing calculations                                                                                                                                                                             
      int texNum = worldMap[mapX][mapY] - 1; //1 subtracted from it so that texture 0 can be used!                                                                                                         

      //calculate value of wallX                                                                                                                                                                           
      double wallX; //where exactly the wall was hit                                                                                                                                                       
      if(side == 0) wallX = posY + perpWallDist * rayDirY;
      else          wallX = posX + perpWallDist * rayDirX;
      wallX -= floor((wallX));

      //x coordinate on the texture                                                                                                                                                                        
      int texX = (int)(wallX * (double)(texWidth));
      if(side == 0 && rayDirX > 0) texX = texWidth - texX - 1;
      if(side == 1 && rayDirY < 0) texX = texWidth - texX - 1;

      // TODO: an integer-only bresenham or DDA like algorithm could make the texture coordinate stepping faster                                                                                           
      // How much to increase the texture coordinate per screen pixel                                                                                                                                      
      double step = 1.0 * texHeight / lineHeight;
      // Starting texture coordinate                                                                                                                                                                       
      double texPos = (drawStart - pitch - SCREEN_HEIGHT / 2 + lineHeight / 2) * step;
      for(int y = drawStart; y < drawEnd; y++)
      {
        // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow                                                                                                       
        int texY = (int)texPos & (texHeight - 1);
        texPos += step;
        Uint32 color = texture[texNum][texHeight * texY + texX];
        //make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"                                                                                              
        if(side == 1) color = (color >> 1) & 8355711;
        buffer[y][x] = color;
      }
    }
 //draw buffer

 Uint32* bufp;
  bufp = (Uint32*)instance.window.pixels;

  for(int y = 0; y < SCREEN_HEIGHT; y++)
  {
    for(int x = 0; x < SCREEN_WIDTH; x++)
    {
      *bufp = buffer[y * SCREEN_WIDTH + x];
      bufp++;
    }
    bufp += instance.window->pitch / 4;
    bufp -= SCREEN_WIDTH;
  }


SDL_SetRenderDrawColor(instance.renderer, 0, 128, 0, 0);
SDL_RenderClear(instance.renderer);
if (keyDown(SDL_SCANCODE_M) && mac == 0)
mac = 1;
else if (keyDown(SDL_SCANCODE_N) && mac == 1)
mac = 0;

/*
 *Draw some stuff here                                                   
 */
background(&instance, &SCREEN_HEIGHT, &SCREEN_WIDTH);
position(worldMap, &SCREEN_WIDTH, &SCREEN_HEIGHT, instance,
         &posX, &posY, &dirX, &dirY, &planeX, &planeY, &mac);
SDL_RenderPresent(instance.renderer);
}
/*Free resources and close SDL*/
SDL_DestroyRenderer(instance.renderer);
SDL_DestroyWindow(instance.window);
SDL_Quit();
free_map(worldMap);

int j = 7;
while (j > -1)
{
free(texture[j]);
j--;
}
 free(texture);
return(0);
}
