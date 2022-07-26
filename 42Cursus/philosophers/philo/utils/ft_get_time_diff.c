/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time_diff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 19:52:22 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/27 00:44:26 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

long long	ft_get_time_diff(struct timeval start, struct timeval tv)
{
	long long	ret;

	ret = tv.tv_sec - start.tv_sec;
	ret *= 1000000;
	ret += tv.tv_usec - start.tv_usec;
	return (ret);
}