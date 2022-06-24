/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 21:12:54 by chanhale          #+#    #+#             */
/*   Updated: 2022/06/24 21:19:39 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	init_map(t_map *map)
{
	map->size_x = 0;
	map->size_y = 0;
	map->enemies = NULL;
	map->obstacles = NULL;
	map->user.pos.next = NULL;
	map->user.pos.x = 0;
	map->user.pos.y = 0;
	map->user.state = 0;
}

t_pos	*forge_ememy(int pos_x, int pos_y, t_map *map)
{
	t_pos	*ret;
	t_pos	**temp_pos;

	ret = (t_pos *)malloc(sizeof(t_pos));
	if (!ret)
		emergency_exit(map, 1);
	ret->next = NULL;
	ret->x = pos_x;
	ret->y = pos_y;
	temp_pos = &(map->enemies);
	while (*temp_pos)
		temp_pos = &((*temp_pos)->next);
	*temp_pos = ret;
	return (ret);
}

t_pos	*forge_obstacle(int pos_x, int pos_y, t_map *map)
{
	t_pos	*ret;
	t_pos	**temp_pos;

	ret = (t_pos *)malloc(sizeof(t_pos));
	if (!ret)
		emergency_exit(map, 1);
	ret->next = NULL;
	ret->x = pos_x;
	ret->y = pos_y;
	temp_pos = &(map->obstacles);
	while (*temp_pos)
		temp_pos = &((*temp_pos)->next);
	*temp_pos = ret;
	return (ret);
}

void	emergency_exit(t_map *map, int exit_code)
{
	t_pos	*temp_pos;

	if (map)
	{
		while (map->enemies)
		{
			temp_pos = map->enemies->next;
			free (map->enemies);
			map->enemies = temp_pos;
		}
		while (map->obstacles)
		{
			temp_pos = map->obstacles->next;
			free (map->obstacles);
			map->obstacles = temp_pos;
		}
	}
	exit(exit_code);
}
