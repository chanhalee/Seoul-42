/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:29:38 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/23 02:56:43 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb);

int	ft_is_prime(int nb)
{
	int	rt;
	int	divider;

	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	rt = ft_sqrt(nb);
	divider = 2;
	while (nb % divider && divider <= rt)
		divider ++;
	if (divider > rt)
		return (1);
	return (0);
}

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
			if (nb < base * base)
				return (base);
		return (46340);
	}
	while (++base <= i * 1000)
		if (nb < base * base)
			return (base);
	return (46340);
}
