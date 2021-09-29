/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoyoon <yeoyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:19:27 by yeoyoon           #+#    #+#             */
/*   Updated: 2021/09/29 17:40:17 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_struct.h"

static int	g_x_check;

int	check_all(int fd, t_map *map)
{
	int	y_counter;
	int	d_l_check;

	d_l_check = 0;
	y_counter = 0;
	while (check_line(fd, map, y_counter, &d_l_check))
		y_counter++;
	if (y_counter != map -> size_col || d_l_check != map -> size_col)
		return (0);
	return (1);
}

int	check_line(int fd, t_map *map, int y_counter, int *d_l_check)
{
	char	c;
	int		x_counter;

	x_counter = 0;
	if (read(fd, &c, 1))
	{
		while (c == '\n')
			return (0);
		(*d_l_check)++;
		x_counter = check_char(c, map, x_counter, y_counter);
		while (read(fd, &c, 1))
		{
			if (c == '\n')
				break ;
			x_counter = check_char(c, map, x_counter, y_counter);
		}
		if (g_x_check == 0)
			g_x_check = set_g_x_counter(x_counter, map);
		if (x_counter != g_x_check)
			return (0);
		return (1);
	}
	return (0);
}

int	check_char(char c, t_map *map, int x_counter, int y_counter)
{
	if (c == (map -> obstacle_c))
		save_obstacle(&(map -> front_line), x_counter, y_counter, map);
	if (c == (map -> empty_c) || c == (map -> obstacle_c))
		x_counter++;
	else
		return (-1);
	return (x_counter);
}

int	check_file(char *file_name, t_map *map)
{
	int	fd;

	g_x_check = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		write(1, "map error\n", 10);
		return (0);
	}
	if (!(save_first(fd, map) && check_all(fd, map)))
	{
		close(fd);
		write(1, "map error\n", 10);
		return (0);
	}
	close (fd);
	return (1);
}
