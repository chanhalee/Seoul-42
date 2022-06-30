/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:34:37 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/01 03:20:20 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./so_long.h"

void	mlx_asset_init(t_mlx_data *mlx_data)
{
	int		img_h;
	int		img_w;

	mlx_data->idle0 = mlx_xpm_file_to_image(mlx_data->mlx, "./images/knight/idle/idle0.xpm", &img_w, &img_h);
	mlx_data->idle1 = mlx_xpm_file_to_image(mlx_data->mlx, "./images/knight/idle/idle1.xpm", &img_w, &img_h);
	mlx_data->idle2 = mlx_xpm_file_to_image(mlx_data->mlx, "./images/knight/idle/idle2.xpm", &img_w, &img_h);
	mlx_data->idle3 = mlx_xpm_file_to_image(mlx_data->mlx, "./images/knight/idle/idle3.xpm", &img_w, &img_h);
	mlx_data->idle4 = mlx_xpm_file_to_image(mlx_data->mlx, "./images/knight/idle/idle4.xpm", &img_w, &img_h);
	mlx_data->idle5 = mlx_xpm_file_to_image(mlx_data->mlx, "./images/knight/idle/idle5.xpm", &img_w, &img_h);
	mlx_data->run0 = mlx_xpm_file_to_image(mlx_data->mlx, "./images/knight/run/run0.xpm", &img_w, &img_h);
	mlx_data->run1 = mlx_xpm_file_to_image(mlx_data->mlx, "./images/knight/run/run1.xpm", &img_w, &img_h);
	mlx_data->run2 = mlx_xpm_file_to_image(mlx_data->mlx, "./images/knight/run/run2.xpm", &img_w, &img_h);
	mlx_data->run3 = mlx_xpm_file_to_image(mlx_data->mlx, "./images/knight/run/run3.xpm", &img_w, &img_h);
	mlx_data->run4 = mlx_xpm_file_to_image(mlx_data->mlx, "./images/knight/run/run4.xpm", &img_w, &img_h);
	mlx_data->run5 = mlx_xpm_file_to_image(mlx_data->mlx, "./images/knight/run/run5.xpm", &img_w, &img_h);
	mlx_data->wall = mlx_xpm_file_to_image(mlx_data->mlx, "./images/tile/wall.xpm", &img_w, &img_h);
	mlx_data->exit_open = mlx_xpm_file_to_image(mlx_data->mlx, "./images/tile/exit_open.xpm", &img_w, &img_h);
	mlx_data->grass = mlx_xpm_file_to_image(mlx_data->mlx, "./images/tile/grass.xpm", &img_w, &img_h);
	mlx_data->chest_open = mlx_xpm_file_to_image(mlx_data->mlx, "./images/tile/chest_open.xpm", &img_w, &img_h);
	mlx_data->chest_closed = mlx_xpm_file_to_image(mlx_data->mlx, "./images/tile/chest_closed.xpm", &img_w, &img_h);
}