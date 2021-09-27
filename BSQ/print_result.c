#include "library/my_struct.h"

void print(t_map *map)
{
	int	index_x;
	int	index_y;
	int	x_s;
	int x_e;
	int y_s;
	int y_e;

	index_y = -1;
	map->front_line = map->obstacle_head->next;
	x_s = map->square.location.row - map->square.size + 1;
	x_e = map->square.location.row;
	y_s = map->square.location.col - map->square.size + 1;
	y_e = map->square.location.col;
	while (++index_y < map->size_col)
	{
		index_x = -1;
		while (++index_x < map->size_row) {
			if (index_x <= x_e && index_x >= x_s && index_y <= y_e && index_y >= y_s)
				write(1, &(map->square_c), 1);
			else
				if (index_y == map->front_line->col && index_x == map->front_line->row)
				{
					write(1, &(map->obstacle_c), 1);
					if(map->front_line->next != NULL)
						map->front_line = map->front_line->next;
				}
				else
					write(1, &(map->empty_c), 1);
		}
		write(1, "\n", 1);
	}
}