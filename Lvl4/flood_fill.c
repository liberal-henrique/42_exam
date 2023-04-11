typedef struct  s_point
{
  int           x;
  int           y;
}               t_point;

#include "./flood_fill.h"

void fill(char **tab, t_point size, char target, int x, int y)
{
    if ((x >= size.x) || (y >= size.y) || x < 0 || y < 0)
        return ;
	if (tab[y][x] != target)
		return ;
	tab[y][x] = 'F';
    fill(tab, size, target, x + 1, y);
    fill(tab, size, target, x - 1, y);
    fill(tab, size, target, x, y + 1);
    fill(tab, size, target, x, y - 1);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
    char target;

    target = tab[begin.y][begin.x];
    fill(tab, size, target, begin.x, begin.y);
}
