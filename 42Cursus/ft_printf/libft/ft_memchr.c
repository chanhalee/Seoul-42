/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:15:10 by chanhale          #+#    #+#             */
/*   Updated: 2022/01/04 15:53:24 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*casted_s;

	if (n == 0)
		return (NULL);
	casted_s = (const unsigned char *)s;
	while (n--)
	{
		if (*casted_s == (unsigned char)c)
			return ((void *)casted_s);
		casted_s++;
	}
	return (NULL);
}
