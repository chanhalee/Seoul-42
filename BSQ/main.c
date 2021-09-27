#include "library/my_struct.h"
#include <stdio.h>


int main(int argc, char **argv) {
	t_map	*map;

	map_init(&map);

	check_file(argv[1], map);

	open_file(argv[1], map);
	search(map);
	printf("col: %d, row:  %d, square: %d, x: %d, y: %d\n",map->size_col,
		   map->size_row, map->square.size, map->square.location.row,  map->square.location.col);
	print(map);
	return 0;
}

void map_init(t_map **map)
{
	(*map) = (t_map *)malloc(sizeof (t_map));
	(*map)->obstacle_head = (t_dot *)malloc(sizeof (t_dot));
	(*map)->front_line = (*map)->obstacle_head;
	(*map)->square.size = 0;
	(*map)->square.location.row = 0;
	(*map)->square.location.col = 0;
	(*map)->square.location.next = NULL;
}

void save_obstacle(t_dot **front_line, int row, int col)
{
	(*front_line)->next = (t_dot *)malloc(sizeof (t_dot));
	(*front_line)->next->row = row;
	(*front_line)->next->col = col;
	(*front_line)->next->next = NULL;
	(*front_line) = (*front_line)->next;
}