/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:53:48 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/03 21:32:14 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

void	mlx_set_enemy_img(t_mlx_data *mlx, t_pos *enemy);
void	move_enemy(t_mlx_data *mlx, size_t new_x, size_t new_y, t_pos *enemy);
int		check_and_move_enemy(t_mlx_data *mlx, size_t x, size_t y, t_pos *enemy);

t_pos	*forge_enemy(size_t pos_x, size_t pos_y, t_map *map)
{
	t_pos	*ret;

	ret = (t_pos *)malloc(sizeof(t_pos));
	if (!ret)
		emergency_exit_bonus(map, TYPE_ERR_CODE_MALLOC);
	ret->next = map->enemies;
	ret->x = pos_x;
	ret->y = pos_y;
	ret->state = TYPE_OBJECT_STATE_INITIAL;
	map->enemies = ret;
	return (ret);
}

void	move_enemies(t_mlx_data *mlx)
{
	t_pos	*enemy;
	size_t	x;
	size_t	y;
	int		ret;

	enemy = mlx->map.enemies;
	while (enemy != NULL)
	{
		x = enemy->x;
		y = enemy->y;
		ret = 0;
		if (enemy->state == 0 || ret == 1)
			ret = check_and_move_enemy(mlx, enemy->x, enemy->y - 1, enemy);
		if (enemy->state == 1 || ret == 1)
			ret = check_and_move_enemy(mlx, enemy->x - 1, enemy->y, enemy);
		if (enemy->state == 2 || ret == 1)
			ret = check_and_move_enemy(mlx, enemy->x + 1, enemy->y, enemy);
		if (enemy->state == 3 || ret == 1)
			if (check_and_move_enemy(mlx, enemy->x, enemy->y + 1, enemy))
				check_and_move_enemy(mlx, enemy->x, enemy->y - 1, enemy);
		enemy = enemy->next;
	}
}

int	check_and_move_enemy(t_mlx_data *mlx, size_t x, size_t y, t_pos *enemy)
{
	t_pos	*object;

	object = mlx->map.enemies;
	while (object != NULL)
	{
		if (object->x == x && object->y == y)
		{
			enemy->state = (enemy->state + 1) % 4;
			return (1);
		}
		object = object->next;
	}
	object = mlx->map.obstacles;
	while (object != NULL)
	{
		if (object->x == x && object->y == y)
		{
			enemy->state = (enemy->state + 1) % 4;
			return (1);
		}
		object = object->next;
	}
	move_enemy(mlx, x, y, enemy);
	return (0);
}

void	move_enemy(t_mlx_data *mlx, size_t new_x, size_t new_y, t_pos *enemy)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->grass,
		16 * enemy->x, 16 * enemy->y);
	if (check_matching_entry(mlx->map.collectibles, enemy->x, enemy->y)
		== TYPE_TRUE)
	{
		if (get_object_state(mlx->map.collectibles, enemy->x, enemy->y)
			== TYPE_OBJECT_STATE_COLLECTED)
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->c_open,
				16 * enemy->x, 16 * enemy->y);
		else
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->c_closed,
				16 * enemy->x, 16 * enemy->y);
	}
	else if (check_matching_entry(mlx->map.exits, enemy->x, enemy->y)
		== TYPE_TRUE)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->exit,
			16 * enemy->x, 16 * enemy->y);
	enemy->x = new_x;
	enemy->y = new_y;
	mlx_set_enemy_img(mlx, enemy);
}

void	mlx_set_enemy_img(t_mlx_data *mlx, t_pos *enemy)
{
	if (enemy->state == 0)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->enemy_down,
			16 * enemy->x, 16 * enemy->y);
	else if (enemy->state == 1)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->enemy_left,
			16 * enemy->x, 16 * enemy->y);
	else if (enemy->state == 2)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->enemy_right,
			16 * enemy->x, 16 * enemy->y);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->enemy_up,
			16 * enemy->x, 16 * enemy->y);
}
