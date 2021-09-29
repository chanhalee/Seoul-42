/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoyoon <yeoyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:19:43 by yeoyoon           #+#    #+#             */
/*   Updated: 2021/09/28 17:19:56 by yeoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_struct.h"

int	std_in_arg(t_map **map)
{
	map_init(map);
	if (!(save_first(0, *map) && check_all(0, *map)))
	{
		write(1, "map error\n", 10);
		return (0);
	}
	search(*map);
	print(*map);
	return (1);
}
