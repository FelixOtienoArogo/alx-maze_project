#ifndef MAZE_H
#define MAZE_H

#include <SDL2/SDL.h>
#include <stdio.h>
/**
 *struct SDL_Instance - the struct to hold my sdl instance
 *
 *@window: the window to be worked on
 *@renderer: the renderer for our drawings
 *@worldMap: our map
 */
typedef struct SDL_Instance
{
SDL_Window *window;
SDL_Renderer *renderer;/*the single SDL surface used*/
char **worldMap;
} SDL_Instance;

int init(SDL_Instance *, const int SCREEN_WIDTH, const int SCREEN_HEIGHT);
int poll_events(void);
int draw_stuff(SDL_Instance *instance, int *drawStart, int *drawEnd,
	       int x, const int *SCREEN_HEIGHT, const int *SCREEN_WIDTH, int size);
float arcToRad(float arcAngle);
void map(SDL_Instance *instance);
int hitMiss(double *rayDirX, double *rayDirY, double *posX, double *posY,
	    int *mapX, int *mapY, double *deltaDistX, double *deltaDistY,
	    double *sideDistX, double *sideDistY, int hit, char **worldMap);
void drawDim(int *drawStart, int *drawEnd, double *perpWallDist,
	     const int *SCREEN_HEIGHT);
void position(char **worldMap, const int *SCREEN_WIDTH,
	      const int *SCREEN_HEIGHT, SDL_Instance instance,
	      double *posX, double *posY, double *dirX, double *dirY,
	      double *planeX, double *planeY, int *mac);
double time(void);
void motion(char **worldMap, double *posX, double *posY, double *dirX,
	    double *dirY, double *planeX, double *planeY);
int keyDown(int key);
int background(SDL_Instance *instance, const int *SCREEN_HEIGHT,
	       const int *SCREEN_WIDTH);
void free_map(char **map);
void miniMap(SDL_Instance *instance);
void ray(int hit, int *mac, SDL_Instance instance, double *posX,
	 double *posY, int mapY, int mapX);
#endif
