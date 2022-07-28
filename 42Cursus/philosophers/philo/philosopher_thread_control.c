/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_thread_control.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 22:30:48 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/28 21:42:45 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int	philosopher_thread_create_sub(t_bigbro *bigbro);

int	philosopher_thread_create(t_bigbro *bigbro)
{
	struct timeval	tv;
	t_philosopher	*now;
	int				ret;
	int				counter;

	gettimeofday(&tv, NULL);
	set_starting_time(bigbro, tv);
	now = bigbro->philosophers_head;
	counter = -1;
	while (++counter < bigbro->number_of_philos)
	{
		ret = pthread_create(&(now->tid), NULL,
				(void *)philosopher_thread_main, now);
		if (ret != 0)
		{
			ret = now->number;
			now = bigbro->philosophers_head;
			while (now->number < ret)
				philo_set_state(now, TYPE_STATE_DEAD);
			return (ret);
		}
		pthread_detach(now->tid);
		now = now->next;
	}
	return (philosopher_thread_create_sub(bigbro));
}

int	philosopher_thread_create_sub(t_bigbro *bigbro)
{
	t_philosopher	*now;
	int				counter;

	while (1)
	{
		pthread_mutex_lock(&(bigbro->permission_to_speak));
		if (bigbro->speakable)
		{
			pthread_mutex_unlock(&(bigbro->permission_to_speak));
			usleep(100);
		}
		else
			break ;
	}
	pthread_mutex_unlock(&(bigbro->permission_to_speak));
	now = bigbro->philosophers_head;
	counter = -1;
	while (++counter < bigbro->number_of_philos)
	{
		philo_set_state(now, TYPE_STATE_DEAD);
		philo_terminate(now);
		now = now->next;
	}
	return (0);
}
