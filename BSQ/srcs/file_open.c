/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoyoon <yeoyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:19:16 by yeoyoon           #+#    #+#             */
/*   Updated: 2021/09/28 17:19:19 by yeoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_struct.h"

int	save_first(int fd, t_map *map)
{
	char	buf[3];

	map -> size_col = read_first(fd, buf);
	if ((map -> size_col) == 0)
		return (0);
	map -> empty_c = buf[0];
	map -> obstacle_c = buf[1];
	map -> square_c = buf[2];
	return (1);
}

int	read_first(int fd, char *buf)
{
	int		i;
	int		col;
	char	c;

	col = 0;
	i = 0;
	while (i < 3)
	{
		if (read(fd, &c, 1) != -1)
			buf[i++] = c;
		else
			return (0);
	}
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			break ;
		col = (col * 10) + buf[0] - 48;
		set_buf(buf, c);
	}
	if (buf[0] == buf[1] || buf[1] == buf[2]
		|| buf[0] == buf[2])
		return (0);
	return (col);
}

void	set_buf(char *buf, char c)
{
	buf[0] = buf[1];
	buf[1] = buf[2];
	buf[2] = c;
}

int	set_g_x_counter(int x_counter, t_map *map)
{
	map -> size_row = x_counter;
	return (x_counter);
}
