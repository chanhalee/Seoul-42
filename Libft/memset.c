/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:39:50 by chanhale          #+#    #+#             */
/*   Updated: 2021/11/10 16:11:43 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	write_val;
	size_t			iter;
	unsigned char	*casted_b;

	iter = 0;
	casted_b = (unsigned char *)b;
	write_val = (unsigned char) c;
	while (iter < len)
		casted_b[iter++] = write_val;
	return (b);
}
