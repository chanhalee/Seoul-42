#include "library/my_struct.h"

void search(t_map *map)
{
	int			*prev_line;
	int			*current_line;
	int			index_y;
	int			index_x;

	index_x = -1;
	index_y = -1;
	prev_line = (int *)malloc(sizeof (int) * (map->size_row + 1));
	current_line = (int *)malloc(sizeof (int) * (map->size_row + 1));
	map->front_line = map->obstacle_head->next;
	while (++index_x < map->size_row)
		prev_line[index_x] = 0;
	search_sub(prev_line, current_line, map, -1);
	free(prev_line);
	free(current_line);
}

void search_sub(int *prev_line, int *current_line, t_map *map, int index_y)
{
	int	index_x;

	while (++index_y < map->size_col)
	{
		index_x = -1;
		while (++index_x < map->size_row)
			if (map->front_line->row == index_x &&  map->front_line->col == index_y)
			{
				current_line[index_x] = 0;
				if (map->front_line->next != NULL)
					map->front_line = map->front_line->next;
			}
			else {
				if (index_x == 0)
					current_line[0] = 1;
				else
					current_line[index_x] = search_merge(prev_line, current_line, index_x);
				if (current_line[index_x] > map->square.size) {
					map->square.size = current_line[index_x];
					map->square.location.row = index_x;
					map->square.location.col = index_y;
				}
			}
		search_switch(current_line, prev_line, map->size_row);
	}
}

int search_merge(int *prev_line, int *current_line, int index_x)
{
	if (prev_line[index_x - 1] < prev_line[index_x])
	{
		if (prev_line[index_x - 1] < current_line[index_x - 1])
			return (prev_line[index_x - 1] + 1);
		else if (current_line[index_x - 1] < prev_line[index_x])
			return (current_line[index_x - 1] + 1);
	}
	if(prev_line[index_x] < current_line[index_x - 1])
		return (prev_line[index_x] + 1);
	return (current_line[index_x - 1] + 1);
}

void search_switch(int *curr, int *prev, int size)
{
	int	local_index;

	local_index = -1;
	while(++local_index != size)
	{
		prev[local_index] = curr[local_index];
		curr[local_index] = 0;
	}
}