#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 *free - free resources after running the programming
 *
 *Return: nothing
 */
void free_map(char **map)
{
int i = 0;
while(map[i])
{
free(map[i]);
i++;
}
free(map);
}
