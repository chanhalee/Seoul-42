/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_thread_control.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 22:30:48 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/26 23:37:51 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int	philosopher_thread_create(t_bigbro *bigbro)
{
	struct timeval	tv;
	t_philosopher	*now;
	int				ret;

	gettimeofday(&tv, NULL);
	set_starting_time(bigbro, tv);
	now = bigbro->philosophers_head;
	while(now->number < bigbro->number_of_philos)
	{
		printf("%d\n", now->number );
		ret = pthread_create(&(now->tid),  NULL, (void *)philosopher_thread_main, now);
		if (ret != 0)
		{
			ret = now->number;
			now = bigbro->philosophers_head;
			while(now->number < ret)
				philo_set_state(now, TYPE_STATE_DEAD);
			return (ret);
		}
		now = now->next;
	}
	ret = pthread_create(&(now->tid),  NULL, (void *)philosopher_thread_main, now);
			printf("%d\n", now->number );
	if (ret != 0)
	{
		ret = now->number;
		now = bigbro->philosophers_head;
		while(now->number < ret)
			philo_set_state(now, TYPE_STATE_DEAD);
		return (ret);
	}
	return (0);
}

void	philosopher_thread_join(t_bigbro *bigbro, int error_ret)
{
	t_philosopher	*now;

	if (error_ret == 0)
		error_ret = bigbro->number_of_philos +1;
	now = bigbro->philosophers_head;
	while (--error_ret > 0)
	{
		pthread_join(now->tid, NULL);
		now = now->next;
	}
}