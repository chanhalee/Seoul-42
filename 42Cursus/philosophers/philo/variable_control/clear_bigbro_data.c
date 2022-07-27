/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_bigbro_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:18:46 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/27 14:00:53 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	clear_bigbro_data(t_bigbro *bigbro)
{
	int	index;

	pthread_mutex_destroy(&(bigbro->permission_to_speak));
	index = -1;
	while (++index < bigbro->number_of_philos)
		pthread_mutex_destroy(&(bigbro->forks[index]));
	free(bigbro->forks);
	free_all_philosopher_data(bigbro);
}
