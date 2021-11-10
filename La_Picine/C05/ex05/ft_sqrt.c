/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:12:03 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/23 14:17:19 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;
	int	base;

	i = 1;
	if (nb < 0)
		return (0);
	while (nb > 1000000 * i * i && i < 47)
		i++;
	base = (i - 1) * 1000 - 1;
	if (base == 45999)
	{
		while (++base <= 46340)
			if (nb == base * base)
				return (base);
		return (0);
	}
	while (++base <= i * 1000)
		if (nb == base * base)
			return (base);
	return (0);
}
