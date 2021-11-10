/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:15:32 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/19 16:32:13 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	destlength;
	int	srclength;

	srclength = 0;
	destlength = 0;
	while (dest[destlength] != '\0')
		destlength++;
	dest[destlength] = 48;
	while (src[srclength] != '\0')
	{
		dest[destlength + srclength] = src[srclength];
		srclength++;
	}
	dest[destlength + srclength] = '\0';
	return (dest);
}
