/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chahale@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 03:04:48 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/26 10:41:10 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	int	temp;

	temp = 0;
	while (str[temp] != '\0')
	{
		temp++;
	}
	write(1, str, temp);
}

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

void	ft_show_tab(struct s_stock_str *par)
{
	int	index;

	index = -1;
	while (par[++index].str != 0)
	{
		ft_putstr(par[index].str);
		write(1, "\n", 1);
		ft_putnbr(par[index].size);
		write(1, "\n", 1);
		ft_putstr(par[index].copy);
		write(1, "\n", 1);
	}
}
