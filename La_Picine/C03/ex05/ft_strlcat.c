/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 17:54:33 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/26 17:23:56 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	destlength;
	unsigned int	srclength;
	unsigned int	cy;
	unsigned int	len;

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
