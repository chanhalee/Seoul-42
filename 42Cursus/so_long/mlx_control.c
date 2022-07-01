/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:34:37 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/01 18:24:56 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	mlx_asset_init_sub(t_mlx_data *mlx_data);
void	mlx_make_render_sub(t_mlx_data *mlx, size_t x, size_t y);

void	mlx_asset_init(t_mlx_data *mlx_data)
{
	int		img_h;
	int		img_w;

	mlx_data->idle0 = mlx_xpm_file_to_image(mlx_data->mlx,
			"./images/knight/idle/idle0.xpm", &img_w, &img_h);
	mlx_data->idle1 = mlx_xpm_file_to_image(mlx_data->mlx,
			"./images/knight/idle/idle1.xpm", &img_w, &img_h);
	mlx_data->idle2 = mlx_xpm_file_to_image(mlx_data->mlx,
			"./images/knight/idle/idle2.xpm", &img_w, &img_h);
	mlx_data->idle3 = mlx_xpm_file_to_image(mlx_data->mlx,
			"./images/knight/idle/idle3.xpm", &img_w, &img_h);
	mlx_data->idle4 = mlx_xpm_file_to_image(mlx_data->mlx,
			"./images/knight/idle/idle4.xpm", &img_w, &img_h);
	mlx_data->idle5 = mlx_xpm_file_to_image(mlx_data->mlx,
			"./images/knight/idle/idle5.xpm", &img_w, &img_h);
	mlx_data->run0 = mlx_xpm_file_to_image(mlx_data->mlx,
			"./images/knight/run/run0.xpm", &img_w, &img_h);
	mlx_asset_init_sub(mlx_data);
}

void	mlx_asset_init_sub(t_mlx_data *mlx_data)
{
	int		img_h;
	int		img_w;

	mlx_data->run1 = mlx_xpm_file_to_image(mlx_data->mlx,
			"./images/knight/run/run1.xpm", &img_w, &img_h);
	mlx_data->run2 = mlx_xpm_file_to_image(mlx_data->mlx,
			"./images/knight/run/run2.xpm", &img_w, &img_h);
	mlx_data->run3 = mlx_xpm_file_to_image(mlx_data->mlx,
			"./images/knight/run/run3.xpm", &img_w, &img_h);
	mlx_data->run4 = mlx_xpm_file_to_image(mlx_data->mlx,
			"./images/knight/run/run4.xpm", &img_w, &img_h);
	mlx_data->run5 = mlx_xpm_file_to_image(mlx_data->mlx,
			"./images/knight/run/run5.xpm", &img_w, &img_h);
	mlx_data->wall = mlx_xpm_file_to_image(mlx_data->mlx,
			"./images/tile/wall.xpm", &img_w, &img_h);
	mlx_data->exit = mlx_xpm_file_to_image(mlx_data->mlx,
			"./images/tile/exit.xpm", &img_w, &img_h);
	mlx_data->grass = mlx_xpm_file_to_image(mlx_data->mlx,
			"./images/tile/grass.xpm", &img_w, &img_h);
	mlx_data->c_open = mlx_xpm_file_to_image(mlx_data->mlx,
			"./images/tile/chest_open.xpm", &img_w, &img_h);
	mlx_data->c_closed = mlx_xpm_file_to_image(mlx_data->mlx,
			"./images/tile/chest_closed.xpm", &img_w, &img_h);
}

void	mlx_make_render(t_mlx_data *mlx)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < mlx->map.size_y)
	{
		x = 0;
		while (x < mlx->map.size_x)
		{
			mlx_make_render_sub(mlx, x, y);
			x++;
		}
		y++;
	}
}

void	mlx_make_render_sub(t_mlx_data *mlx, size_t x, size_t y)
{
	size_t	p_x;
	size_t	p_y;

	p_x = 16 * x;
	p_y = 16 * y;
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->grass, p_x, p_y);
	if (check_matching_entry(mlx->map.obstacles, x, y) == TYPE_TRUE)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->wall, p_x, p_y);
	else if (check_matching_entry(mlx->map.collectibles, x, y) == TYPE_TRUE)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->c_closed, p_x, p_y);
	else if (check_matching_entry(mlx->map.exits, x, y) == TYPE_TRUE)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->exit, p_x, p_y);
	else if (mlx->map.user.pos.x == x && mlx->map.user.pos.y == y)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->idle0, p_x, p_y);
}
