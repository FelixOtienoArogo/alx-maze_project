#include "../headers/maze.h"
#include <stdio.h>
/**
 *map - returns the map of the game
 *
 *@instance: the sdl instance
 *
 *Return: the map
 */
void map(SDL_Instance *instance)
{
char character[100 + 1];
char **map;
int i = 0;
FILE *fpointer;
char *path = "data/map.txt";

fpointer = fopen(path, "r");

if (fpointer == NULL)
{
printf("File does not exist\n");
exit(0);
}

map = malloc((100) * sizeof(char *));
while (fgets(character, sizeof(character), fpointer))
{
map[i] = malloc(sizeof(character));
strcpy(map[i], character);
i++;
}
fclose(fpointer);

*instance =
(SDL_Instance)
{
NULL, NULL, map
};
}
