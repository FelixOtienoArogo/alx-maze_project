#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 *free_map - free resources after running the programming
 *
 *@map: the map to be freed
 *
 *Return: nothing
 */
void free_map(char **map)
{
int i = 0;
while (map[i])
{
free(map[i]);
i++;
}
free(map);
}
