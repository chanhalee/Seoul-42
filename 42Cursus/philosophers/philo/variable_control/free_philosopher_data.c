/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philosopher_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:30:47 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/27 13:59:51 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	free_all_philosopher_data(t_bigbro *bigbro)
{
	t_philosopher	*next;

	next = bigbro->philosophers_head;
	if (bigbro->philosophers_head == NULL)
		return (-1);
	bigbro->philosophers_tail->next = NULL;
	while (next != NULL)
	{
		pthread_mutex_destroy(&(next->state_mutex));
		bigbro->philosophers_head = next->next;
		free(next);
		next = bigbro->philosophers_head;
	}
	bigbro->philosophers_tail = NULL;
	return (-1);
}
