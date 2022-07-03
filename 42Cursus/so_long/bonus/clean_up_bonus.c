/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:05:56 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/03 21:32:12 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

int	mlx_cleanup(t_mlx_data *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	emergency_exit_bonus(&(mlx->map), 0);
	return (0);
}
