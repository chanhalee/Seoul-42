/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chahale@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 00:18:19 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/21 02:01:57 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	iterator(int i, int n, char *base);
int		checkbase(char *base);

void	ft_putnbr_base(int nbr, char *base)
{
	int	n;

	n = checkbase(base);
	if (n)
		iterator(nbr, n, base);
}

void	iterator(int i, int n, char *base)
{
	char	c;

	if (i < 0)
	{
		write(1, "-", 1);
		c = base[(i % n) * -1];
		if ((i / n) * -1 > 0)
			iterator((i / n) * -1, n, base);
		write(1, &c, 1);
	}
	else
	{
		if (i >= n)
		{
			iterator(i / n, n, base);
		}
		write(1, base + i % n, 1);
	}
}

int	checkbase(char *base)
{
	int		i1;
	int		i2;

	i1 = 0;
	while (base[i1] && base[i1] != '-' && base[i1] != '+'
		&& base[i1] != '\t' && base[i1] != '\n' && base[i1] != '\v'
		&& base[i1] != ' ' && base[i1] != '\f' && base[i1] != '\r')
	{
		i2 = i1 + 1;
		while (base[i2] && base[i2] != base[i1])
			i2++;
		if (base[i2] != '\0')
			return (0);
		i1++;
	}
	if (i1 == 0 || i1 == 1)
		return (0);
	if (base[i1] != '\0')
		return (0);
	return (i1);
}
