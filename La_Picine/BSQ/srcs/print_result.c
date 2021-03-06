/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoyoon <yeoyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:19:35 by yeoyoon           #+#    #+#             */
/*   Updated: 2021/09/28 17:19:36 by yeoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_struct.h"

void	print(t_map *map)
{
	int	x_s;
	int	x_e;
	int	y_s;

	map->front_line = map->obstacle_head->next;
	x_s = map->square.location.row - map->square.size + 1;
	x_e = map->square.location.row;
	y_s = map->square.location.col - map->square.size + 1;
	print_inner(map, x_s, x_e, y_s);
}

void	print_inner(t_map *map, int xs, int xe, int ys)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->size_col)
	{
		x = -1;
		while (++x < map->size_row)
		{
			if (x <= xe && x >= xs && y <= map->square.location.col && y >= ys)
				write(1, &(map->square_c), 1);
			else
			{
				if (map->front_line != NULL && y == map->front_line->col
					&& x == map->front_line->row)
				{
					write(1, &(map->obstacle_c), 1);
					map->front_line = map->front_line->next;
				}
				else
					write(1, &(map->empty_c), 1);
			}
		}
		write(1, "\n", 1);
	}
}
