/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_util_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:48:11 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/03 21:32:15 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

int	get_object_state(t_pos *entry, size_t x, size_t y)
{
	t_pos	*next;

	next = entry;
	while (next != NULL)
	{
		if (next->x == x && next->y == y)
			return (next->state);
		next = next ->next;
	}
	return (TYPE_FALSE);
}

void	check_enemy_capture(t_mlx_data *mlx)
{
	if (mlx->map.movement_count % 2)
		move_enemies(mlx);
	if (check_matching_entry(mlx->map.enemies, mlx->map.user.pos.x,
			mlx->map.user.pos.y) == TYPE_TRUE)
	{
		write(1, "\n********************\n*******CAPTURED******\n\n", 45);
		write(1, "move_count:", 11);
		ft_putnbr_custom(mlx->map.movement_count);
		write(1, "\n", 1);
		mlx_cleanup(mlx);
	}
}
