/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigbro_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:55:57 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/26 23:32:18 by chanhale         ###   ########.fr       */
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