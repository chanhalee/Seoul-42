/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:18:42 by chanhale          #+#    #+#             */
/*   Updated: 2022/01/04 15:33:35 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*casted_dst;
	const char	*casted_src;

	if (dst == NULL || src == NULL)
		return (NULL);
	casted_dst = (char *)dst;
	casted_src = (char *)src;
	while (n--)
	{
		*casted_dst = *casted_src;
		casted_dst++;
		casted_src++;
	}
	return (dst);
}
