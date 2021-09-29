/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoyoon <yeoyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:19:22 by yeoyoon           #+#    #+#             */
/*   Updated: 2021/09/28 17:19:23 by yeoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_struct.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	int		loop;

	map = NULL;
	loop = 0;
	if (argc > 1)
	{
		while (++loop < argc)
			got_arg(loop, &map, argv);
	}
	else
		std_in_arg(&map);
	mem_free(map);
	return (0);
}

void	got_arg(int loop, t_map **map, char **argv)
{
	map_init(map);
	if (check_file(argv[loop], *map))
	{
		search(*map);
		print(*map);
	}
}

void	map_init(t_map **map)
{
	(*map) = (t_map *)malloc(sizeof (t_map));
	(*map)->obstacle_head = (t_dot *)malloc(sizeof (t_dot));
	(*map)->front_line = (*map)->obstacle_head;
	(*map)->square.size = 0;
	(*map)->square.location.row = 0;
	(*map)->square.location.col = 0;
	(*map)->square.location.next = NULL;
}

void	save_obstacle(t_dot **front_line, int row, int col, t_map *map)
{
	(*front_line)->next = (t_dot *)malloc(sizeof (t_dot));
	if ((*front_line)->next == NULL)
		fail(1, map);
	(*front_line)->next->row = row;
	(*front_line)->next->col = col;
	(*front_line)->next->next = NULL;
	(*front_line) = (*front_line)->next;
}
