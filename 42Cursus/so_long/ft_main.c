#include "./so_long.h"

int main(int argc, char **argv)
{
	t_map	*map;
	map = get_empty_map();
	parse_map(argv[1], map);
	printf("%zu\n", map->size_x);
	return (0);
}