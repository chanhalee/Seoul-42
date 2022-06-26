# include "./so_long.h"

int parse_map(char *file_name, t_map *map)
{
	int			fd;
	char		*next_line;
	size_t		pos_y;
	char		buff;

    fd = open(file_name, O_RDONLY);
	if (fd < 0)
		emergency_exit(map, TYPE_ERR_CODE_FILE);
	while (read(fd, &buff, 1) > 0 && buff == '1')
		(map->size_x)++;
	if (buff != '\n')
		emergency_exit(map, TYPE_ERR_CODE_MAP);
	next_line = get_next_line(fd);
	map->size_x = ft_strlen(next_line);
	while (!next_line) // 각 라인 0번째는 wall
	{
		pos_y++;
		parse_line(next_line, map, pos_y);
		next_line = get_next_line(fd);
	}
}
void	parse_line(char *line, t_map *map, size_t pos_y)
{
	size_t	pos_x;

	pos_x = 0;
	(map->size_y)++;
	if(*line != '1')
		emergency_exit(map, TYPE_ERR_CODE_MAP);
	while (line[++pos_x] != NULL)
	{
		parse_block(line[pos_x], map, pos_x, pos_y);
	}
}

void	parse_block(char block, t_map *map, size_t pos_x, size_t pos_y)
{
	if (block == '1')
		forge_obstacle(pos_x, pos_y, map);
	else if (block == 'C')
		forge_collectibles(pos_x, pos_y, map);
	else if (block == 'E')
		forge_exit(pos_x, pos_y, map);
	else if (block != '0')
		emergency_exit(map, TYPE_ERR_CODE_MAP);
}