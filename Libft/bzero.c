/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:47:29 by chanhale          #+#    #+#             */
/*   Updated: 2021/11/10 16:02:55 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char			*cast_temp;
	size_t			iter;
	unsigned char	last_byte;

	cast_temp = (char *) s;
	iter = 0;
	last_byte = 0xff;
	while (iter < n)
	{
		if (n - iter > 8)
		{
			*cast_temp &= 0x00;
			iter += 8;
			cast_temp++;
		}
		else
		{
			last_byte = last_byte << (n - iter);
			break ;
		}
	}
	*cast_temp &= last_byte;
}
