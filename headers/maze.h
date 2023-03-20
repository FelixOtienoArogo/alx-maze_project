#ifndef MAZE_H
#define MAZE_H

#include <SDL2/SDL.h>
#include <stdio.h>

typedef struct SDL_Instance
{
SDL_Window *window;
SDL_Renderer *renderer;/*the single SDL surface used*/
int worldMap[24][24];
} SDL_Instance;

int init(SDL_Instance *, const int SCREEN_WIDTH, const int SCREEN_HEIGHT);
int poll_events(void);
int draw_stuff(SDL_Instance *instance, int *drawStart, int *drawEnd,
	       int x, const int *SCREEN_HEIGHT, const int *SCREEN_WIDTH, int size);
float arcToRad(float arcAngle);
void map(SDL_Instance *instance);
int hitMiss(double *rayDirX, double *rayDirY, double *posX, double *posY,
            int *mapX, int *mapY, double *deltaDistX, double *deltaDistY,
            double *sideDistX, double *sideDistY, int hit, int (*worldMap)[24]);
void drawDim(int *drawStart, int *drawEnd, double *perpWallDist, const int *SCREEN_HEIGHT);
void position(int (*worldMap)[24], const int *SCREEN_WIDTH, const int *SCREEN_HEIGHT, SDL_Instance instance, double *posX, double *posY, double *dirX, double *dirY, double *planeX, double *planeY);
double time(void);
void motion(int (*worldMap)[24], double *posX, double *posY, double *dirX,
            double *dirY, double *planeX, double *planeY);
int keyDown(int key);
int background(SDL_Instance *instance,const int *SCREEN_HEIGHT,
               const int *SCREEN_WIDTH);
#endif
