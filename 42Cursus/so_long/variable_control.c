/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 21:12:54 by chanhale          #+#    #+#             */
/*   Updated: 2022/06/27 21:40:52 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	init_map(t_map *map)
{
	map->size_x = 0;
	map->size_y = 0;
	map->movement_count = 0;
	map->collecible_count = 0;
	map->enemies = NULL;
	map->obstacles = NULL;
	map->collectibles = NULL;
	map->exits = NULL;
	map->user.pos.next = NULL;
	map->user.pos.x = 0;
	map->user.pos.y = 0;
	map->user.state = 0;
}

t_pos	*forge_ememy(size_t pos_x, size_t pos_y, t_map *map)
{
	t_pos	*ret;

	ret = (t_pos *)malloc(sizeof(t_pos));
	if (!ret)
		emergency_exit(map, TYPE_ERR_CODE_MALLOC);
	ret->next = map->enemies;
	ret->x = pos_x;
	ret->y = pos_y;
	ret->state = 0;
	map->enemies = ret;
	return (ret);
}

t_pos	*forge_obstacle(size_t pos_x, size_t pos_y, t_map *map)
{
	t_pos	*ret;

	ret = (t_pos *)malloc(sizeof(t_pos));
	if (!ret)
		emergency_exit(map, TYPE_ERR_CODE_MALLOC);
	ret->next = map->obstacles;
	ret->x = pos_x;
	ret->y = pos_y;
	ret->state = 0;
	map->obstacles = ret;
	return (ret);
}

t_pos	*forge_collectibles(size_t pos_x, size_t pos_y, t_map *map)
{
	t_pos	*ret;

	ret = (t_pos *)malloc(sizeof(t_pos));
	if (!ret)
		emergency_exit(map, TYPE_ERR_CODE_MALLOC);
	ret->next = map->collectibles;
	ret->x = pos_x;
	ret->y = pos_y;
	ret->state = 0;
	map->collectibles = ret;
	(map->collecible_count)++;
	return (ret);
}

t_pos	*forge_exit(size_t pos_x, size_t pos_y, t_map *map)
{
	t_pos	*ret;

	ret = (t_pos *)malloc(sizeof(t_pos));
	if (!ret)
		emergency_exit(map, TYPE_ERR_CODE_MALLOC);
	ret->next = map->exits;
	ret->x = pos_x;
	ret->y = pos_y;
	ret->state = 0;
	map->exits = ret;
	return (ret);
}