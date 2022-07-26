/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philosopher_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:22:23 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/24 19:45:22 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	add_empty_philosopher_at_tail_sub(t_bigbro *bigbro, t_philosopher	*ret);
t_philosopher	*add_empty_philosopher_at_tail(t_bigbro *bigbro, int number);

int create_philosopher_data(t_bigbro *bigbro)
{
	int				counter;
	t_philosopher	*result;

	counter = 0;
	while (++counter <= bigbro->number_of_philos)
	{
		result = add_empty_philosopher_at_tail(bigbro, counter);
		if (result == NULL)
			return (free_all_philosopher_data(bigbro));
	}
	return (0);
}

t_philosopher	*add_empty_philosopher_at_tail(t_bigbro *bigbro, int number)
{
	t_philosopher	*ret;

	ret = (t_philosopher *)malloc(sizeof(t_philosopher));
	if (ret == NULL)
		return (NULL);
	if (pthread_mutex_init(&(ret->state_mutex), NULL) != 0)
	{
		free(ret);
		return (NULL);
	}
	ret->l_fork = &(bigbro->forks[number-1]);
	if (number == bigbro->number_of_philos)
		ret->r_fork = &(bigbro->forks[0]);
	else
		ret->r_fork = &(bigbro->forks[number]);
	ret->permission_to_speak = &(bigbro->permission_to_speak);
	ret->number = number;
	ret->next = bigbro->philosophers_head;
	ret->prev =  bigbro->philosophers_tail;
	add_empty_philosopher_at_tail_sub(bigbro, ret);
	return (ret);
}

void	add_empty_philosopher_at_tail_sub(t_bigbro *bigbro, t_philosopher	*ret)
{
	ret->state = TYPE_STATE_THINK;
	ret->last_eat.tv_sec = 0;
	ret->last_eat.tv_usec = 0;
	ret->eat_count = 0;
	ret->time_to_die = bigbro->time_to_die;
	ret->time_to_eat = bigbro->time_to_eat;
	ret->time_to_sleep = bigbro->time_to_sleep;
	if (bigbro->philosophers_head != NULL)
		bigbro->philosophers_head->prev = ret;
	else
		bigbro->philosophers_head = ret;
	if (bigbro->philosophers_tail != NULL)
		bigbro->philosophers_tail->next = ret;
	bigbro->philosophers_tail = ret;
}
