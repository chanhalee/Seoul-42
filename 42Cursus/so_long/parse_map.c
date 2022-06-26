/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 23:45:55 by chanhale          #+#    #+#             */
/*   Updated: 2022/06/27 00:07:57 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./so_long.h"

int parse_map(char *file_name, t_map *map)
{
	int			fd;
	char		*next_line;
	char		*prev_line;
	size_t		pos_y;
	char		buff;

	prev_line = NULL;
    fd = open(file_name, O_RDONLY);
	if (fd < 0)
		emergency_exit(map, TYPE_ERR_CODE_FILE);
	if (buff != '\n')
		emergency_exit(map, TYPE_ERR_CODE_MAP);
	next_line = get_next_line(fd);
	if (next_line == NULL)
		emergency_exit(map, TYPE_ERR_CODE_FILE);
	map->size_x = ft_strlen(next_line);
	if (check_only_wall_in_line(next_line) != 0)
		emergency_exit(map, TYPE_ERR_CODE_MAP);
	while (!next_line) // 각 라인 0번째는 wall
	{
		if (ft_strlen(next_line) != map->size_x)
			emergency_exit(map, TYPE_ERR_CODE_MAP);
		parse_line(next_line, map, pos_y);
		if (prev_line)
			free(prev_line);
		prev_line = next_line;
		next_line = get_next_line(fd);
		if (next_line == NULL)
			emergency_exit(map, TYPE_ERR_CODE_FILE);
		pos_y++;
	}
	if (check_only_wall_in_line(prev_line) != 0)
		emergency_exit(map, TYPE_ERR_CODE_MAP);
	if (prev_line)
		free(prev_line);
}
void	parse_line(char *line, t_map *map, size_t pos_y)
{
	size_t	pos_x;

	pos_x = 0;
	(map->size_y)++;
	if(*line != '1')
		emergency_exit(map, TYPE_ERR_CODE_MAP);
	while (line[pos_x] != '\0')
	{
		parse_block(line[pos_x], map, pos_x, pos_y);
		pos_x++;
	}
	if (line[pos_x - 1] != '1')
		emergency_exit(map, TYPE_ERR_CODE_MAP);
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