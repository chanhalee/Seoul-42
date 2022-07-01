/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:05:56 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/01 18:27:20 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"./so_long.h"

int	mlx_cleanup(t_mlx_data *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	emergency_exit(&(mlx->map), 0);
	return (0);
}
