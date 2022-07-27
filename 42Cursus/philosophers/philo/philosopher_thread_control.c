/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_thread_control.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 22:30:48 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/27 15:02:22 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

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
			printf("1\n");
				philo_set_state(now, TYPE_STATE_DEAD);
			printf("2\n");
			return (ret);
		}
		now = now->next;
	}
	return (0);
}

void	philosopher_thread_join(t_bigbro *bigbro, int error_ret)
{
	t_philosopher	*now;

	usleep(10000);
	if (error_ret == 0)
		error_ret = bigbro->number_of_philos +1;
	now = bigbro->philosophers_head;
	while (--error_ret > 0)
	{
		pthread_join(now->tid, NULL);
		now = now->next;
	}
}
