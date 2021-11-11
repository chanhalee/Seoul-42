/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chahale@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 02:20:50 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/23 01:12:17 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		c = 48 + (nb % 10) * -1;
		if ((nb / 10) * -1 > 0)
			ft_putnbr((nb / 10) * -1);
		write(1, &c, 1);
	}
	else
	{
		if (nb >= 10)
		{
			ft_putnbr(nb / 10);
		}
		c = 48 + nb % 10;
		write(1, &c, 1);
	}
}