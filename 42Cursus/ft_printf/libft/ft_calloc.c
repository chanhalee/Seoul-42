/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:27:51 by chanhale          #+#    #+#             */
/*   Updated: 2021/12/30 21:49:14 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*result;
	unsigned char	*iter_result;
	size_t			iter;

	iter = 0;
	result = (unsigned char *)malloc(sizeof(unsigned char) * count * size);
	if (result == NULL)
		return (NULL);
	iter_result = result;
	while (iter < count * size)
		iter_result[iter++] = 0;
	return ((void *)result);
}
