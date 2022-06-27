#include "./so_long.h"

int main(int argc, char **argv)
{
	t_map	map;
	init_map(&map);
	parse_map(argv[1], &map);
	return (0);
}