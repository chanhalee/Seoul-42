/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 01:32:06 by chanhale          #+#    #+#             */
/*   Updated: 2021/12/29 02:46:54 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*casted_s1;
	const unsigned char	*casted_s2;

	casted_s1 = (const unsigned char *)s1;
	casted_s2 = (const unsigned char *)s2;
	if ((s1 == NULL && s2 == NULL) || n == 0)
		return (0);
	if (s1 == NULL)
		return (-1 * (*casted_s2));
	if (s2 == NULL)
		return (*casted_s1);
	while (n--)
	{
		if (*casted_s1 != *casted_s2)
			return (*casted_s1 - *casted_s2);
		casted_s1++;
		casted_s2++;
	}
	return (0);
}
