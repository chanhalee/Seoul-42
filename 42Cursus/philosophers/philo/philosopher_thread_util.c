/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_thread_util.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:10:18 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/28 12:41:42 by chanhale         ###   ########.fr       */
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

	ret = state;
	ret = pthread_mutex_lock(&(philo->state_mutex));
	gettimeofday(&tv, NULL);
	if (ret != 0)
		return (-1);
	else
	{
		philo->state = state;
		if (state == TYPE_STATE_EAT)
		{
			gettimeofday(&(philo->last_eat), NULL);
			if (philo->eat_count != -1)
				philo->eat_count--;
			if (philo->eat_count == 0)
				ret = bigbro_set_philo_done(philo);
		}
	}
	pthread_mutex_unlock(&(philo->state_mutex));
	return (ret);
}

void	philo_broadcast_state(t_philosopher *philo, char *str, int silence)
{
	int	res;

	res = pthread_mutex_lock(philo->permission_to_speak);
	if (res != 0)
		return ;
	if (*(philo->speakable))
	{
		if (ft_strncmp(str, "died", 4) == 0)
			*(philo->speakable) = 0;
		res = ft_get_time_gap(philo->starting_time) / 1000;
		if (!silence)
			printf("%d %d %s\n", res, philo->number, str);
	}
	pthread_mutex_unlock(philo->permission_to_speak);
}

int	check_philo_vital(t_philosopher *philo, int silence)
{
	if (silence || (philo_get_state(philo) != TYPE_STATE_DEAD
			&& ft_get_time_gap(philo->last_eat) > (philo->time_to_die * 1000)))
	{
		philo_broadcast_state(philo, "died", silence);
		pthread_mutex_lock(philo->permission_to_speak);
		philo_set_state(philo, TYPE_STATE_DEAD);
		pthread_mutex_unlock(philo->permission_to_speak);
		return (TYPE_STATE_DEAD);
	}
	return (philo_get_state(philo));
}

int	philo_terminate(t_philosopher *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->permission_to_speak);
	pthread_mutex_unlock(&(philo->state_mutex));
	return (TYPE_STATE_DEAD);
}
