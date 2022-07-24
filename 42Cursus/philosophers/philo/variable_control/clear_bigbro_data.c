/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_bigbro_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:18:46 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/24 19:35:44 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	clear_bigbro_data(t_bigbro *bigbro)
{
	pthread_mutex_destroy(&(bigbro->permission_to_speak));
	free_all_philosophers(bigbro);
}