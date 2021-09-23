/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 17:54:33 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/23 20:58:28 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	destlength;
	unsigned int	destlencpy;
	unsigned int	srclength;
	unsigned int	len;

	srclength = 0;
	destlength = 0;
	len = 0;
	while (dest[destlength] != '\0')
		destlength++;
	while (src[srclength])
		srclength++;
	if (size == 0)
		return (srclength);
	while (destlength < size - 1 && src[len])
	{
		dest[destlength++] = src[len++];
		srclength++;
	}
	dest[destlength] = '\0';
	return (srclength);
}
