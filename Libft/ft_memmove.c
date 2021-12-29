/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:18:39 by chanhale          #+#    #+#             */
/*   Updated: 2021/12/29 14:49:00 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*casted_dst;
	const char	*casted_src;
	size_t		index;

	if (dst == NULL || src == NULL)
		return (dst);
	casted_dst = (char *)dst;
	casted_src = (const char *)src;
	index = -1;
	if (len == 0)
		return (dst);
	if (casted_dst > casted_src)
	{
		while (len--)
			casted_dst[len] = casted_src[len];
	}
	else
	{
		while (++index < len)
			casted_dst[index] = casted_src[index];
	}
	return (dst);
}
