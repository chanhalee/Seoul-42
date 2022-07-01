/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 23:45:55 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/01 18:46:19 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	parse_map_subsidiary(t_map *map, char *prev_line,
			char *next_line, int fd);
void	parse_line(char *line, t_map *map, size_t pos_y);
void	parse_block(char block, t_map *map, size_t pos_x, size_t pos_y);

void	parse_map(char *file_name, t_map *map)
{
	int			fd;
	char		*next_line;
	char		*prev_line;

	prev_line = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		emergency_exit(map, TYPE_ERR_CODE_FILE);
	next_line = get_next_line(fd);
	if (next_line == NULL)
		emergency_exit(map, TYPE_ERR_CODE_FILE);
	map->size_x = ft_strlen(next_line);
	if (ft_strlen(next_line) < 1 || map->size_x <= 2)
		emergency_exit(map, TYPE_ERR_CODE_MAP);
	if (check_only_wall_in_line(next_line) != 0)
		emergency_exit(map, TYPE_ERR_CODE_MAP);
	parse_map_subsidiary(map, prev_line, next_line, fd);
}

void	parse_map_subsidiary(t_map *map, char *prev_line,
		char *next_line, int fd)
{
	size_t	pos_y;

	pos_y = 0;
	while (next_line)
	{
		if (ft_strlen(next_line) != map->size_x)
			emergency_exit(map, TYPE_ERR_CODE_MAP);
		parse_line(next_line, map, pos_y);
		if (prev_line)
			free(prev_line);
		prev_line = next_line;
		next_line = get_next_line(fd);
		pos_y++;
	}
	if (check_only_wall_in_line(prev_line) != 0)
		emergency_exit(map, TYPE_ERR_CODE_MAP);
	if (prev_line)
		free(prev_line);
	if (map->collectibles == NULL || map->exits == NULL || map->user.pos.x == 0
		|| map->size_x < 3 || map -> size_y < 3)
		emergency_exit(map, TYPE_ERR_CODE_MAP);
}

void	parse_line(char *line, t_map *map, size_t pos_y)
{
	size_t	pos_x;

	pos_x = 0;
	(map->size_y)++;
	if (*line != '1')
		emergency_exit(map, TYPE_ERR_CODE_MAP);
	while (line[pos_x] != '\0' && line[pos_x] != '\n')
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
	else if (block == 'P')
	{
		map->user.pos.x = pos_x;
		map->user.pos.y = pos_y;
	}
	else if (block != '0')
		emergency_exit(map, TYPE_ERR_CODE_MAP);
}
