/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:18:42 by chanhale          #+#    #+#             */
/*   Updated: 2021/11/10 16:10:26 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char		*casted_dst;
	const char	*casted_src;

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