/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bigbro_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:58:17 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/26 23:38:14 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

t_bigbro	*init_bigbro_data_sub(t_bigbro *ret);

int	init_bigbro_data(t_bigbro *bigbro, char **argv)
{
	int			index;

	bigbro->number_of_philos = ft_atoi(argv[1]);
	bigbro->time_to_die = ft_atoi(argv[2]);
	bigbro->time_to_eat = ft_atoi(argv[3]);
	bigbro->time_to_sleep = ft_atoi(argv[4]);
	bigbro->philosophers_head = NULL;
	bigbro->philosophers_tail = NULL;
	if (argv[5] != NULL)
		bigbro->mandatory_eat_count = ft_atoi(argv[5]);
	else 
		bigbro->mandatory_eat_count = -1;
	if (bigbro->number_of_philos <= 0 || bigbro->time_to_die <= 0
		|| bigbro->time_to_eat <= 0 || bigbro->time_to_sleep <= 0
		|| (argv[5] != NULL && bigbro->mandatory_eat_count <= 0)
		|| pthread_mutex_init(&(bigbro->permission_to_speak), NULL) != 0)
		return (-1);
	bigbro->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * bigbro->number_of_philos);
	if (bigbro->forks == NULL)
	{
		return (-1);
	}
	index = -1;
	while (++index < bigbro->number_of_philos)
	{
		if (pthread_mutex_init(&(bigbro->forks[index]), NULL) != 0)
		{
			while(--index >= 0)
				pthread_mutex_destroy(&(bigbro->forks[index]));
			pthread_mutex_destroy(&(bigbro->permission_to_speak));
			free(bigbro->forks);
			return (-1);
		}
	}
	if (create_philosopher_data(bigbro) != 0)
	{
		while(--index >= 0)
			pthread_mutex_destroy(&(bigbro->forks[index]));
		pthread_mutex_destroy(&(bigbro->permission_to_speak));
		free(bigbro->forks);
		return (-1);
	}
	return (0);
}

t_bigbro	*init_bigbro_data_sub(t_bigbro *ret)
{
	return (NULL);
}