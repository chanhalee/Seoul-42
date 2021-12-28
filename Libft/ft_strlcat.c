/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:47:29 by chanhale          #+#    #+#             */
/*   Updated: 2021/11/10 12:50:28 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	destlength;
	size_t	srclength;
	size_t	cy;
	size_t	len;

	srclength = 0;
	destlength = 0;
	len = 0;
	while (dest[destlength] != '\0')
		destlength++;
	while (src[srclength])
		srclength++;
	cy = destlength;
	if (size <= cy)
		return (srclength + size);
	while (destlength < size - 1 && src[len])
	{
		dest[destlength++] = src[len++];
	}
	dest[destlength] = '\0';
	return (srclength + cy);
}
