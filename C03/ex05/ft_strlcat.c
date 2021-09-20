/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 17:54:33 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/21 00:05:43 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	destlength;
	unsigned int	destlencpy;
	unsigned int	srclength;

	srclength = 0;
	destlength = 0;
	while (dest[destlength] != '\0')
		destlength++;
	destlencpy = destlength;
	while (src[srclength] != '\0' && destlencpy++ < size - 1)
	{
		dest[destlength + srclength] = src[srclength];
		srclength++;
	}
	dest[destlength + srclength] = '\0';
	srclength = 0;
	while (src[srclength])
		srclength++;
	if (size < destlength)
		return (size + srclength);
	return (destlength + srclength);
}
