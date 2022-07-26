/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time_gap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 19:52:22 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/27 01:04:41 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

long long	ft_get_time_gap(struct timeval tv)
{
	struct timeval	now;
	long long		ret;

	ret = gettimeofday(&now, NULL);
	if (ret == -1)
		return (-1);
	ret = now.tv_sec - tv.tv_sec;
	ret *= 1000000;
	ret += now.tv_usec - tv.tv_usec;
	return (ret);
}