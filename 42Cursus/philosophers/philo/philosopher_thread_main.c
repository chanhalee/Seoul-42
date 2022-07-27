/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_thread_main.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 22:34:04 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/27 15:08:35 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

void	philo_take_fork(t_philosopher *philo, int count);
void	philo_lose_fork(t_philosopher *philo, int count);
int		check_vital_while_sleep(t_philosopher *philo,
			struct timeval start, long long sleep_time);
int		philosopher_thread_main_innerseq(t_philosopher *philo,
			struct timeval tv);

int	philosopher_thread_main(t_philosopher *philo)
{
	struct timeval	tv;
	int				inner_ret;

	check_vital_while_sleep(philo, philo->starting_time, 200);
	if (philo->number % 2)
		check_vital_while_sleep(philo, philo->starting_time, 100);
	while (philo_get_state(philo) != TYPE_STATE_DEAD)
	{
		if (check_philo_vital(philo, 0) == TYPE_STATE_DEAD)
			return (philo_terminate(philo));
		philo_take_fork(philo, 1);
		if (check_philo_vital(philo, 0) == TYPE_STATE_DEAD)
			return (philo_terminate(philo));
		philo_broadcast_state(philo, "has taken a fork", 0);
		philo_take_fork(philo, 2);
		gettimeofday(&tv, NULL);
		inner_ret = philosopher_thread_main_innerseq(philo, tv);
		if (inner_ret != 0)
			return (inner_ret);
	}
	return (philo_terminate(philo));
}

int	philosopher_thread_main_innerseq(t_philosopher *philo, struct timeval tv)
{
	if (check_philo_vital(philo, 0) == TYPE_STATE_DEAD)
		return (philo_terminate(philo));
	philo_broadcast_state(philo, "has taken a fork", 0);
	philo_broadcast_state(philo, "is eating", 0);
	if (philo_set_state(philo, TYPE_STATE_EAT) == -1)
		if (check_philo_vital(philo, 1) == TYPE_STATE_DEAD)
			return (philo_terminate(philo));
	if (check_vital_while_sleep(philo, tv, philo->time_to_eat
			* 1000) == TYPE_STATE_DEAD)
		return (philo_terminate(philo));
	philo_lose_fork(philo, 1);
	philo_lose_fork(philo, 2);
	gettimeofday(&tv, NULL);
	philo_set_state(philo, TYPE_STATE_SLEEP);
	philo_broadcast_state(philo, "is sleeping", 0);
	if (check_vital_while_sleep(philo, tv, philo->time_to_sleep
			* 1000) == TYPE_STATE_DEAD)
		return (philo_terminate(philo));
	philo_set_state(philo, TYPE_STATE_THINK);
	return (0);
}

void	philo_take_fork(t_philosopher *philo, int count)
{
	if ((philo->number % 2 == 1 && count == 1)
		|| (philo->number % 2 == 0 && count == 2))
	{
		pthread_mutex_lock(philo->l_fork);
	}
	else
		pthread_mutex_lock(philo->r_fork);
}

void	philo_lose_fork(t_philosopher *philo, int count)
{
	if ((philo->number % 2 == 1 && count == 1)
		|| (philo->number % 2 == 0 && count == 2))
	{
		pthread_mutex_unlock(philo->r_fork);
	}
	else
		pthread_mutex_unlock(philo->l_fork);
}

int	check_vital_while_sleep(t_philosopher *philo,
		struct timeval start, long long sleep_time)
{
	while (ft_get_time_gap(start) < sleep_time)
	{
		if (check_philo_vital(philo, 0) == TYPE_STATE_DEAD)
			return (TYPE_STATE_DEAD);
		usleep(100);
	}
	return (philo_get_state(philo));
}