/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bigbro_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:58:17 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/27 14:27:38 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	init_bigbro_data_sub(t_bigbro *bigbro, int index);

int	init_bigbro_data(t_bigbro *bigbro, char **argv)
{
	bigbro->number_of_philos = ft_atoi(argv[1]);
	bigbro->time_to_die = ft_atoi(argv[2]);
	bigbro->time_to_eat = ft_atoi(argv[3]);
	bigbro->time_to_sleep = ft_atoi(argv[4]);
	bigbro->philosophers_head = NULL;
	bigbro->philosophers_tail = NULL;
	bigbro->speakable = 1;
	bigbro->number_of_full = -1;
	if (argv[5] != NULL)
		bigbro->mandatory_eat_count = ft_atoi(argv[5]);
	else
		bigbro->mandatory_eat_count = -1;
	if (argv[5] != NULL)
		bigbro->number_of_full = bigbro->number_of_philos;
	if (bigbro->number_of_philos <= 0 || bigbro->time_to_die <= 0
		|| bigbro->time_to_eat <= 0 || bigbro->time_to_sleep <= 0
		|| (argv[5] != NULL && bigbro->mandatory_eat_count <= 0)
		|| pthread_mutex_init(&(bigbro->permission_to_speak), NULL) != 0)
		return (-1);
	return (init_bigbro_data_sub(bigbro, -1));
}

int	init_bigbro_data_sub(t_bigbro *bigbro, int index)
{
	bigbro->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* bigbro->number_of_philos);
	if (bigbro->forks == NULL)
		return (-1);
	while (++index < bigbro->number_of_philos)
	{
		if (pthread_mutex_init(&(bigbro->forks[index]), NULL) != 0)
		{
			while (--index >= 0)
				pthread_mutex_destroy(&(bigbro->forks[index]));
			pthread_mutex_destroy(&(bigbro->permission_to_speak));
			free(bigbro->forks);
			return (-1);
		}
	}
	if (create_philosopher_data(bigbro) != 0)
	{
		while (--index >= 0)
			pthread_mutex_destroy(&(bigbro->forks[index]));
		pthread_mutex_destroy(&(bigbro->permission_to_speak));
		free(bigbro->forks);
		return (-1);
	}
	return (0);
}
