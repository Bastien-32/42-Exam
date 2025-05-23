/* 
Dans la fonction flood_fill
	fill a les memes arguments que flood_fill + tab[begin.y][begin.x]
Attention au sens d'écriture de X et Y
	- Quand on remplit un tableau, c'est Y puis X
	- Quand on remplit un t_list, c'est X puis Y
Dans le if ne pas oublier != to_fill
et dans la recursive, ne pas oublier de caster et de mettre les accolades
 */

typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;
  
void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.x < 0 || cur.y < 0  || cur.x >= size.x || cur.y >= size.y
			|| tab[cur.y][cur.x] != to_fill)
		return;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
	
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}
/* 
#include <stdlib.h>
#include <stdio.h>

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001"};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
} */