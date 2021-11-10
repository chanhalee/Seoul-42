/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:42:54 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/25 00:37:29 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	get_gap(int min, int max);

int	*ft_range(int min, int max)
{
	unsigned int	size;
	int				*result;

	size = get_gap(min, max);
	if (size == 0)
		return (NULL);
	result = (int *)malloc(sizeof(int) * size);
	size = -1;
	while (min != max)
		result[++size] = min++;
	return (result);
}

unsigned int	get_gap(int min, int max)
{
	unsigned int	result;

	if (min >= max)
		return (0);
	result = max - min;
	return (result);
}
