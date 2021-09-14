/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:26:01 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/14 21:40:19 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_print_comb(void)
{
	int		i;
	int		j;
	int		k;
	int		flag;

	flag = 0;
	i = -1;
	while (i++ < 9)
	{
		j = i;
		while (j++ < 9)
		{
			k = j;
			while (k++ < 9)
			{
				if (flag != 0)
				{
					write(1, ",  ", 2);
				}
				flag++;
			}
		}
	}
}

void	subfunc(int i, int j, int k)
{
	char	num[3];

	num[0] = i + 48;
	num[1] = j + 48;
	num[2] = k + 48;
	write(1, num, 3);
}
