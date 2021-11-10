/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:56:03 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/16 11:56:06 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	subfunc(int i, int j);

void	ft_print_comb2(void)
{
	int	preint;
	int	surint;
	int	temp;

	temp = 0;
	preint = 0;
	while (preint < 99)
	{
		surint = preint + 1;
		while (surint < 100)
		{
			if (temp == 0)
			{
				temp++;
			}
			else
			{
				write(1, ", ", 2);
			}
			subfunc(preint, surint);
			surint++;
		}
		preint++;
	}
}

void	subfunc(int i, int j)
{
	char	pre[2];
	char	sur[2];

	pre[1] = 48 + i % 10;
	pre[0] = 48 + i / 10;
	sur[1] = 48 + j % 10;
	sur[0] = 48 + j / 10;
	write(1, pre, 2);
	write(1, " ", 1);
	write(1, sur, 2);
}
