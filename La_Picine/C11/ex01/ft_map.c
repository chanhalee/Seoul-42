/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chahale@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 01:33:29 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/28 01:41:47 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*result;
	int	local_index;

	local_index = -1;
	result = (int *)malloc(sizeof (int) * length);
	while (++local_index < length)
		result[local_index] = (*f)(tab[local_index]);
	return (result);
}
