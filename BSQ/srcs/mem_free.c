/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoyoon <yeoyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:19:31 by yeoyoon           #+#    #+#             */
/*   Updated: 2021/09/29 14:49:10 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_struct.h"

void	mem_free(t_map *map)
{
	t_dot	*next;

	if (map != NULL)
	{
		while (map->obstacle_head != NULL)
		{
			next = map->obstacle_head->next;
			free(map->obstacle_head);
			map->obstacle_head = next;
		}
		free(map);
	}
}

void	fail(int exit_code, t_map *map)
{
	mem_free(map);
	map = NULL;
	exit(exit_code);
}
