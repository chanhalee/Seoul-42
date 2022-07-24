/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_system.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:58:17 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/24 18:47:09 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	init_system(t_bigbro *big_bro, char **argv)
{
	int	convert_res;

	big_bro->number_of_philos = ft_atoi(argv[1]);
	big_bro->time_to_die = ft_atoi(argv[2]);
	big_bro->time_to_eat = ft_atoi(argv[3]);
	big_bro->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		big_bro->mandatory_eat_count = ft_atoi(argv[5]);
	else 
		big_bro->mandatory_eat_count = -1;
	if (big_bro->number_of_philos <= 0 || big_bro->time_to_die <= 0
		|| big_bro->time_to_eat <= 0 || big_bro->time_to_sleep <= 0
		|| (argv[5] != NULL && big_bro->mandatory_eat_count <= 0)
		|| pthread_mutex_init(&(big_bro->permission_to_speak), NULL) != 0)
		return (-1);
	if (create_philosophers(big_bro) != 0)
	{
		pthread_mutex_destroy(&(big_bro->permission_to_speak));
		return (-1);
	}
	return (0);
}
