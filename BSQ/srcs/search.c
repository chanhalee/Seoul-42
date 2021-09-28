/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:46:36 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/28 12:22:57 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_struct.h"

void	search(t_map *map)
{
	int			*prev_line;
	int			*current_line;
	int			index_y;
	int			index_x;

	index_x = -1;
	index_y = -1;
	prev_line = (int *)malloc(sizeof (int) * (map->size_row + 1));
	current_line = (int *)malloc(sizeof (int) * (map->size_row + 1));
	map->front_line = map->obstacle_head->next;
	while (++index_x < map->size_row)
		prev_line[index_x] = 0;
	search_sub(prev_line, current_line, map, -1);
	free(prev_line);
	free(current_line);
}

void	search_sub(int *p_line, int *c_line, t_map *map, int idx_y)
{
	int	idx_x;

	while (++idx_y < map->size_col)
	{
		idx_x = -1;
		while (++idx_x < map->size_row)
		{
			if (map->front_line->row == idx_x && map->front_line->col == idx_y)
			{
				c_line[idx_x] = 0;
				if (map->front_line->next != NULL)
					map->front_line = map->front_line->next;
			}
			else
			{
				if (idx_x == 0)
					c_line[0] = 1;
				else
					c_line[idx_x] = search_merge(p_line, c_line, idx_x);
				if (c_line[idx_x] > map->square.size)
					search_sizeup(&(map->square), c_line[idx_x], idx_x, idx_y);
			}
		}
		search_switch(c_line, p_line, map->size_row);
	}
}

int	search_merge(int *prev_line, int *current_line, int index_x)
{
	if (prev_line[index_x - 1] < prev_line[index_x])
	{
		if (prev_line[index_x - 1] < current_line[index_x - 1])
			return (prev_line[index_x - 1] + 1);
		else if (current_line[index_x - 1] < prev_line[index_x])
			return (current_line[index_x - 1] + 1);
	}
	if (prev_line[index_x] < current_line[index_x - 1])
		return (prev_line[index_x] + 1);
	return (current_line[index_x - 1] + 1);
}

void	search_switch(int *curr, int *prev, int size)
{
	int	local_index;

	local_index = -1;
	while (++local_index != size)
	{
		prev[local_index] = curr[local_index];
		curr[local_index] = 0;
	}
}

void	search_sizeup(t_square *old, int new_size, int new_x, int new_y)
{
	old->size = new_size;
	old->location.row = new_x;
	old->location.col = new_y;
}
