/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:27:51 by chanhale          #+#    #+#             */
/*   Updated: 2021/11/10 16:52:03 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*cast_temp;
	size_t			iter;

	iter = -1;
	cast_temp = (char *)malloc(count * size);
	while (++iter < count * size)
	{
		*cast_temp &= 0x00;
		cast_temp++;
	}
	return ((void *) cast_temp);
}
