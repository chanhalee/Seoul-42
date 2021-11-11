/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:15:10 by chanhale          #+#    #+#             */
/*   Updated: 2021/11/10 16:07:52 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char		casted_c;
	const char	*casted_s;
	size_t		index_plus_one;

	casted_c = (char) c;
	casted_s = (const char *)s;
	index_plus_one = 0;
	while (*casted_s != casted_c && index_plus_one++ < n)
		casted_s++;
	if (*casted_s == casted_c)
		return ((void *)casted_s);
	return (0);
}
