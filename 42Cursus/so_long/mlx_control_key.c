/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_control_key.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:19:10 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/01 20:30:13 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"./so_long.h"

void	mlx_key_up_sub(t_mlx_data *mlx, t_pos res);

int	mlx_key_up(int keycode, t_mlx_data *mlx)
{
	t_pos	res;

	if (keycode == TYPE_KEY_ESC)
		mlx_cleanup(mlx);
	if (keycode != TYPE_KEY_A && keycode != TYPE_KEY_S && keycode
		!= TYPE_KEY_D && keycode != TYPE_KEY_W)
		return (0);
	if (keycode == TYPE_KEY_W && mlx->map.collecible_count == 0
		&& check_matching_entry(mlx->map.exits, mlx->map.user.pos.x,
			mlx->map.user.pos.y) == TYPE_TRUE)
	{
		write(1, "\n********************\n*******FINISH*******\n", 43);
		write(1, "move_count:", 11);
		ft_putnbr_custom(mlx->map.movement_count);
		mlx_cleanup(mlx);
	}
	res = move_position(&(mlx->map), keycode);
	if (res.state != TYPE_RESULT_BLOCKED)
		mlx_key_up_sub(mlx, res);
	return (0);
}

void	mlx_key_up_sub(t_mlx_data *mlx, t_pos res)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->grass,
		16 * res.x, 16 * res.y);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->grass,
		16 * mlx->map.user.pos.x, 16 * mlx->map.user.pos.y);
	if (check_matching_entry(mlx->map.exits, res.x, res.y) == TYPE_TRUE)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->exit,
			16 * res.x, 16 * res.y);
	if (check_matching_entry(mlx->map.exits, mlx->map.user.pos.x,
			mlx->map.user.pos.y) == TYPE_TRUE)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->exit,
			16 * mlx->map.user.pos.x, 16 * mlx->map.user.pos.y);
	if (check_matching_entry(mlx->map.collectibles, res.x, res.y) == TYPE_TRUE)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->c_open,
			16 * res.x, 16 * res.y);
	if (check_matching_entry(mlx->map.collectibles, mlx->map.user.pos.x,
			mlx->map.user.pos.y) == TYPE_TRUE)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->c_open,
			16 * mlx->map.user.pos.x, 16 * mlx->map.user.pos.y);
	mlx_set_user_img(mlx);
	write(1, "\nmovement: ", 11);
	ft_putnbr_custom(mlx->map.movement_count);
}

int	mlx_key_down(int keycode, t_mlx_data *mlx)
{
	if (keycode != TYPE_KEY_A && keycode != TYPE_KEY_S && keycode
		!= TYPE_KEY_D && keycode != TYPE_KEY_W)
		return (0);
	mlx->map.user.state = keycode;
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->grass,
		16 * mlx->map.user.pos.x, 16 * mlx->map.user.pos.y);
	if (check_matching_entry(mlx->map.exits, mlx->map.user.pos.x,
			mlx->map.user.pos.y) == TYPE_TRUE)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->exit,
			16 * mlx->map.user.pos.x, 16 * mlx->map.user.pos.y);
	if (check_matching_entry(mlx->map.collectibles, mlx->map.user.pos.x,
			mlx->map.user.pos.y) == TYPE_TRUE)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->c_open,
			16 * mlx->map.user.pos.x, 16 * mlx->map.user.pos.y);
	mlx_set_user_img(mlx);
	return (0);
}

void	mlx_set_user_img(t_mlx_data *mlx)
{
	if (mlx->map.user.state == TYPE_KEY_S)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->idle_down,
			16 * mlx->map.user.pos.x, 16 * mlx->map.user.pos.y);
	else if (mlx->map.user.state == TYPE_KEY_A)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->idle_left,
			16 * mlx->map.user.pos.x, 16 * mlx->map.user.pos.y);
	else if (mlx->map.user.state == TYPE_KEY_D)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->idle_right,
			16 * mlx->map.user.pos.x, 16 * mlx->map.user.pos.y);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->idle_up,
			16 * mlx->map.user.pos.x, 16 * mlx->map.user.pos.y);
}
