/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:36:02 by chanhale          #+#    #+#             */
/*   Updated: 2022/01/06 16:55:15 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;
	char	*iter_h;

	i = 0;
	iter_h = (char *)h;
	if (n[i] == '\0')
		return (iter_h);
	while (i < len && iter_h[i] != '\0')
	{
		j = 0;
		if (iter_h[i] == n[j])
		{
			while ((iter_h[i + j] == n[j])
				&& (n[j] != '\0') && (i + j < len))
				j++;
			if (n[j] == '\0')
				return (&iter_h[i]);
		}
		i++;
	}
	return (0);
}
