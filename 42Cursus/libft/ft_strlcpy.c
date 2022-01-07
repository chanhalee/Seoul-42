/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:42:01 by chanhale          #+#    #+#             */
/*   Updated: 2022/01/04 15:35:26 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	temp;
	size_t	counter;

	counter = 0;
	temp = 0;
	while (src[counter] != '\0')
		counter++;
	if (size == 0)
		return (counter);
	while (src[temp] != '\0' && temp < size - 1)
	{
		dest[temp] = src[temp];
		temp++;
	}
	dest[temp] = '\0';
	return (counter);
}
