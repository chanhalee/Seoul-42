/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:47:29 by chanhale          #+#    #+#             */
/*   Updated: 2021/12/29 10:38:25 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	destlength;
	size_t	srclength;
	size_t	cy;
	size_t	len;

	srclength = 0;
	destlength = 0;
	len = 0;
	while (dst[destlength] != '\0')
		destlength++;
	while (src[srclength] != '\0')
		srclength++;
	cy = destlength;
	if (size <= destlength)
		return (srclength + size);
	while (destlength < size - 1 && src[len])
	{
		dst[destlength++] = src[len++];
	}
	dst[destlength] = '\0';
	return (srclength + cy);
}
