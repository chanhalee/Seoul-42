/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 23:47:48 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/01 19:10:37 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	check_only_wall_in_line(char *line)
{
	size_t	index;

	index = 0;
	if (line == NULL)
		return (-1);
	while (line[index] != '\n' && line[index] != '\0')
	{
		if (line[index] != '1')
			return (-1);
		index++;
	}
	return (0);
}

int	check_matching_entry(t_pos *entry, size_t x, size_t y)
{
	t_pos	*next;

	next = entry;
	while (next != NULL)
	{
		if (next->x == x && next->y == y)
			return (TYPE_TRUE);
		next = next ->next;
	}
	return (TYPE_FALSE);
}
