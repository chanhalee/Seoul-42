/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 23:47:48 by chanhale          #+#    #+#             */
/*   Updated: 2022/06/26 23:52:28 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./so_long.h"

int	check_only_wall_in_line(char *line)
{
	size_t	index;

	index = 0;
	if (line == NULL)
		return (-1);
	while(line[index])
	{
		if(line[index] != '1')
			return (-1);
		index++;
	}
	return (0);
}
