/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_thread_util.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:10:18 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/27 01:22:11 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int	philo_get_state(t_philosopher *philo)
{
	int	ret;

	ret = pthread_mutex_lock(&(philo->state_mutex));
	if (ret != 0)
		ret = TYPE_STATE_DEAD;
	else
		ret = philo->state;
	pthread_mutex_unlock(&(philo->state_mutex));
	return (ret);
}

int	philo_set_state(t_philosopher *philo, int state)
{
	struct timeval	tv;
	int				ret;
	int				now;

	ret = state;
	ret = pthread_mutex_lock(&(philo->state_mutex));
	gettimeofday(&tv, NULL);
	if (ret != 0)
		ret = -1;
	else
	{
		philo->state = state;
		if (state == TYPE_STATE_EAT)
		{
			gettimeofday(&(philo->last_eat), NULL);
			philo->eat_count++;
		}
	}
	pthread_mutex_unlock(&(philo->state_mutex));
	return (ret);
}

void	philo_broadcast_state(t_philosopher *philo, char *str)
{
	int	res;

	res = pthread_mutex_lock(philo->permission_to_speak);
	if (res != 0)
		return ;
	res = ft_get_time_gap(philo->starting_time) / 1000;
	printf("%d %d %s\n", res, philo->number, str);
	pthread_mutex_unlock(philo->permission_to_speak);
}

int	check_philo_vital(t_philosopher *philo)
{
	t_philosopher	*next;

	if (philo_get_state(philo) != TYPE_STATE_DEAD
		&& ft_get_time_gap(philo->last_eat) > (philo->time_to_die * 1000))
	{
		next = philo->next;
		
		printf("%ld %d\n", ft_get_time_gap(philo->last_eat), (philo->time_to_die * 1000));
		while (next != philo)
		{
			philo_set_state(next, TYPE_STATE_DEAD);
			next = next->next;
		}
		philo_broadcast_state(philo, "died");
		return (TYPE_STATE_DEAD);
	}
	return (philo->state);
}

int	philo_terminate(t_philosopher *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(&(philo->state_mutex));
	return (TYPE_STATE_DEAD);
}
