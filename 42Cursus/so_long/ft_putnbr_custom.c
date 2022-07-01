/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:26:09 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/01 16:26:26 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	ft_putnbr_custom(int n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		c = 48 + (n % 10) * -1;
		if ((n / 10) * -1 > 0)
			ft_putnbr_custom((n / 10) * -1);
		write(1, &c, 1);
	}
	else
	{
		if (n >= 10)
			ft_putnbr_custom(n / 10);
		c = 48 + n % 10;
		write(1, &c, 1);
	}
}
