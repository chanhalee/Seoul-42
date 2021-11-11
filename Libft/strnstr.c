/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:36:02 by chanhale          #+#    #+#             */
/*   Updated: 2021/11/10 16:14:01 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i_h;
	size_t	i_n;

	i_h = -1;
	while (++i_h < len)
	{
		i_n = -1;
		while (n[++i_n] && h[i_h + i_n] && n[i_n] == h[i_h + i_n])
		{
			if (i_h + i_n >= len)
				break ;
		}
		if (i_h + i_n >= len || n[i_n] == '\0')
			break ;
	}
	if (n[i_n] == '\0')
		return ((char *)h + i_h);
	return (NULL);
}
