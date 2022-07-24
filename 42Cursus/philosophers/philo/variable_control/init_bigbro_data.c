/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bigbro_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:58:17 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/24 22:20:47 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

t_bigbro	*init_bigbro_data_sub(t_bigbro *ret);

t_bigbro	*init_bigbro_data(t_bigbro *ret, char **argv)
{
	t_bigbro	*ret;

	ret = (t_bigbro *)malloc(sizeof(t_bigbro));
	if (ret == NULL)
		return(NULL);
	ret->number_of_philos = ft_atoi(argv[1]);
	ret->time_to_die = ft_atoi(argv[2]);
	ret->time_to_eat = ft_atoi(argv[3]);
	ret->time_to_sleep = ft_atoi(argv[4]);
	ret->philosophers_head = NULL;
	ret->philosophers_tail = NULL;
	if (argv[5] != NULL)
		ret->mandatory_eat_count = ft_atoi(argv[5]);
	else 
		ret->mandatory_eat_count = -1;
	if (ret->number_of_philos <= 0 || ret->time_to_die <= 0
		|| ret->time_to_eat <= 0 || ret->time_to_sleep <= 0
		|| (argv[5] != NULL && ret->mandatory_eat_count <= 0)
		|| pthread_mutex_init(&(ret->permission_to_speak), NULL) != 0)
	{
		free(ret);
		return (NULL);
	}
	return (init_bigbro_data_sub(ret));
}

t_bigbro	*init_bigbro_data_sub(t_bigbro *ret)
{
	if (create_philosopher_data(ret) != 0)
	{
		pthread_mutex_destroy(&(ret->permission_to_speak));
		free(ret);
		return (NULL);
	}
	return (ret);
}