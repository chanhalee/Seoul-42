/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 09:16:27 by chanhale          #+#    #+#             */
/*   Updated: 2022/06/27 21:37:59 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	emergency_exit(t_map *map, int exit_code)
{
	t_pos	*temp_pos;

	if (!map)
		print_error_and_exit(exit_code);
	while (map->enemies)
	{
		temp_pos = map->enemies->next;
		free (map->enemies);
		map->enemies = temp_pos;
	}
	while (map->obstacles)
	{
		temp_pos = map->obstacles->next;
		free (map->obstacles);
		map->obstacles = temp_pos;
	}
	while (map->collectibles)
	{
		temp_pos = map->collectibles->next;
		free (map->collectibles);
		map->collectibles = temp_pos;
	}
	while (map->exits)
	{
		temp_pos = map->exits->next;
		free (map->exits);
		map->exits = temp_pos;
	}
	print_error_and_exit(exit_code);
}

void	print_error_and_exit(int exit_code)
{
	if (exit_code == TYPE_ERR_CODE_MALLOC)
		write(2, "Error\nMalloc error\n", 19);
	if (exit_code == TYPE_ERR_CODE_FILE)
		write(2, "Error\nFile error\n", 17);
	if (exit_code == TYPE_ERR_CODE_MAP)
		write(2, "Error\nMap error\n", 16);
	if (exit_code == TYPE_ERR_CODE_MAP)
		write(2, "Error\nMap error\n", 16);
	if (exit_code == TYPE_ERR_CODE_MLX)
		write(2, "Error\nMLX error\n", 16);
	exit(exit_code);
}