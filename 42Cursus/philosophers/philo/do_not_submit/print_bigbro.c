/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bigbro.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:23:29 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/24 19:47:43 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./do_not_submit.h"

void	print_bigbro(t_bigbro *bigbro)
{
	t_philosopher	*philosopher;
	
	if (bigbro == NULL)
	{
		printf("bigbro: NULL\n");
		return ;
	}
	printf("\n=======bigbro========\n\n");
	printf("number_of_philos: %d\n", bigbro->number_of_philos);
	printf("time_to_die: %d\n", bigbro->time_to_die);
	printf("time_to_eat: %d\n", bigbro->time_to_eat);
	printf("time_to_sleep: %d\n", bigbro->time_to_sleep);
	printf("mandatory_eat_count: %d\n", bigbro->mandatory_eat_count);
	philosopher = bigbro->philosophers_head;
	if (philosopher == NULL)
		return ;
	while (philosopher != bigbro->philosophers_tail)
	{
		printf("========phillo[%d]========\n", philosopher->number);
		printf("last_eat: %d\n", philosopher->last_eat);
		printf("state: %d\n", philosopher->state);
		printf("eat_count: %d\n", philosopher->eat_count);
		philosopher = philosopher->next;
	}
	printf("========phillo[%d]========\n", philosopher->number);
	printf("last_eat: %d\n", philosopher->last_eat);
	printf("state: %d\n", philosopher->state);
	printf("eat_count: %d\n", philosopher->eat_count);
	philosopher = philosopher->next;
	printf("\n===========================\n\n");
}
