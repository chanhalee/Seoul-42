/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:44:56 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/01 18:31:55 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	ask_and_move(t_map *map, size_t new_pos_x, size_t new_pos_y);
int	ask_and_move_subsidiary(t_map *map, size_t new_pos_x, size_t new_pos_y);

t_pos	move_position(t_map *map, int move)
{
	t_pos	result;
	size_t	new_pos_x;
	size_t	new_pos_y;

	result.x = map->user.pos.x;
	result.y = map->user.pos.y;
	new_pos_x = map->user.pos.x;
	new_pos_y = map->user.pos.y;
	if (move == TYPE_MOVE_UP)
		new_pos_y -= 1;
	if (move == TYPE_MOVE_DOWN)
		new_pos_y += 1;
	if (move == TYPE_MOVE_LEFT)
		new_pos_x -= 1;
	if (move == TYPE_MOVE_RIGHT)
		new_pos_x += 1;
	result.state = ask_and_move(map, new_pos_x, new_pos_y);
	return (result);
}

int	ask_and_move(t_map *map, size_t new_pos_x, size_t new_pos_y)
{
	t_pos	*object;

	object = map->obstacles;
	while (object != NULL)
	{
		if (object->x == new_pos_x && object->y == new_pos_y)
			return (TYPE_RESULT_BLOCKED);
		object = object->next;
	}
	map->user.pos.x = new_pos_x;
	map->user.pos.y = new_pos_y;
	(map->movement_count)++;
	object = map->collectibles;
	while (object != NULL)
	{
		if (object->x == new_pos_x && object->y == new_pos_y
			&& object->state != TYPE_OBJECT_STATE_COLLECTED)
		{
			object->state = TYPE_OBJECT_STATE_COLLECTED;
			(map->collecible_count)--;
			return (TYPE_RESULT_COLLECTED);
		}
		object = object->next;
	}
	return (ask_and_move_subsidiary(map, new_pos_x, new_pos_y));
}

int	ask_and_move_subsidiary(t_map *map, size_t new_pos_x, size_t new_pos_y)
{
	t_pos	*object;

	object = map->exits;
	if (map->collecible_count == 0)
	{
		while (object != NULL)
		{
			if (object->x == new_pos_x && object->y == new_pos_y)
			{
				object->state = TYPE_OBJECT_STATE_COLLECTED;
				return (TYPE_RESULT_COLLECTED);
			}
			object = object->next;
		}
	}
	return (TYPE_RESULT_MOVED);
}
