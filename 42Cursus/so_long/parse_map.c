# include "./so_long.h"

int parse_map(char *file_name, t_map *map)
{
	int		fd;
	size_t		counter;
	char	buff;

    fd = open(file_name, O_RDONLY);
	if (fd < 0)
		emergency_exit(map, 1);
	counter = 0;
	while (read(fd, &buff, 1) > 0|| buff == '1')
		(map->size_x)++;
	if (buff != '\n')
		emergency_exit(map, 1);
}