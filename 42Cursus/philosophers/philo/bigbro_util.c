/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigbro_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:55:57 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/27 14:25:57 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

void	set_starting_time(t_bigbro *bigbro, struct timeval tv)
{
	t_philosopher	*last;
	t_philosopher	*now;

	last = bigbro->philosophers_tail;
	now = bigbro->philosophers_head;
	if (now == NULL)
		return ;
	while (now != last)
	{
		now->last_eat = tv;
		now->starting_time = tv;
		now = now->next;
	}
	now->last_eat = tv;
	now->starting_time = tv;
}

int	bigbro_set_philo_done(t_philosopher *philo)
{
	int				ret;

	ret = pthread_mutex_lock(philo->permission_to_speak);
	if (ret != 0)
		ret = -1;
	else
	{
		(*(philo->number_of_full))--;
		if (*(philo->number_of_full) == 0)
			ret = -1;
	}
	pthread_mutex_unlock(philo->permission_to_speak);
	return (ret);
}
