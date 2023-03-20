#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 *reader -to read the map into an array
 *
 *
 *Return: the map
 */
int main(void)
{
  char character[100 + 1];
  char **map;
  int i = 0;
  FILE *fpointer;
 
  fpointer = fopen("map.txt", "r");

  if(fpointer == NULL)
    {
    printf("File does not exist");
    exit(0);
    }
map = malloc((100) * sizeof( char *));
while(fgets(character, sizeof(character), fpointer))
{
  map[i] = malloc(sizeof(character));
 strcpy(map[i], character);
 printf("%s", map[i]);
 i++;
 }
fclose(fpointer);
i--;
while(i >= 0)
{
free(map[i]);
i--;
}
  free(map);
  return (0);
}
