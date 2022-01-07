/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 01:32:06 by chanhale          #+#    #+#             */
/*   Updated: 2022/01/04 15:55:04 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*casted_s1;
	const unsigned char	*casted_s2;

	casted_s1 = (const unsigned char *)s1;
	casted_s2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n--)
	{
		if (*casted_s1 != *casted_s2)
			return (*casted_s1 - *casted_s2);
		casted_s1++;
		casted_s2++;
	}
	return (0);
}
