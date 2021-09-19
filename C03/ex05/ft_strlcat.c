/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 17:54:33 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/19 19:56:08 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	destlength;
	unsigned int	srclength;

	srclength = 0;
	destlength = 0;
	while (dest[destlength] != '\0')
		destlength++;
	dest[destlength] = 48;
	while (src[srclength] != '\0' && srclength < size - 1)
	{
		dest[destlength + srclength] = src[srclength];
		srclength++;
	}
	dest[destlength + srclength] = '\0';
	srclength = 0;
	while (src[srclength])
		srclength++;
	return (destlength + srclength);
}
