/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:32:40 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/19 19:59:38 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	destlength;
	unsigned int	srclength;

	srclength = 0;
	destlength = 0;
	while (dest[destlength] != '\0')
		destlength++;
	while (src[srclength] != '\0' && srclength < nb)
	{
		dest[destlength + srclength] = src[srclength];
		srclength++;
	}
	dest[destlength + srclength] = '\0';
	return (dest);
}
