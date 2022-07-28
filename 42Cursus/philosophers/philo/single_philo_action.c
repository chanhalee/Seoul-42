/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_philo_action.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:43:54 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/28 21:50:34 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int	single_philo_action(t_philosopher *philo)
{
	struct timeval	tv;

	pthread_mutex_lock(philo->l_fork);
	philo_broadcast_state(philo, "has taken a fork", 0);
	gettimeofday(&tv, NULL);
	check_vital_while_sleep(philo, tv, philo->time_to_die * 1000);
	philo_broadcast_state(philo, "died", 0);
	return (TYPE_STATE_DEAD);
}
