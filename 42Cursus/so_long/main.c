/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:28:09 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/01 18:28:47 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	main(int argc, char **argv)
{
	t_mlx_data	mlx_data;

	if (argc < 2)
		emergency_exit(NULL, TYPE_ERR_CODE_MLX);
	init_map(&(mlx_data.map));
	parse_map(argv[1], &(mlx_data.map));
	mlx_data.mlx = mlx_init();
	if (mlx_data.mlx == 0)
		emergency_exit(&(mlx_data.map), TYPE_ERR_CODE_MLX);
	mlx_data.win = mlx_new_window(mlx_data.mlx, 16 * (mlx_data.map).size_x,
			16 * (mlx_data.map).size_y, "Hello world!");
	mlx_asset_init(&mlx_data);
	mlx_make_render(&mlx_data);
	mlx_hook(mlx_data.win, 17, 0, mlx_cleanup, &mlx_data);
	mlx_key_hook(mlx_data.win, mlx_key_input, &(mlx_data));
	mlx_loop(mlx_data.mlx);
	mlx_cleanup(&mlx_data);
	return (0);
}
