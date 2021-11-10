/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chahale@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 00:38:43 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/25 00:47:38 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_gap(int min, int max);

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	index;

	size = get_gap(min, max);
	if (size == 0)
	{
		range = NULL;
		return (0);
	}
	*range = (int *)malloc(sizeof(int) * size);
	if (range == NULL)
		return (0);
	index = -1;
	while (min != max)
		(*range)[++index] = min++;
	return (size);
}

int	get_gap(int min, int max)
{
	unsigned int	result;

	if (min >= max)
		return (0);
	result = max - min;
	return (result);
}
