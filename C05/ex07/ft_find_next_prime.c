/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:42:31 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/21 21:56:15 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb);

int	ft_is_prime(int nb)
{
	int rt;
	int divider;
	if (nb < 2)
		return (0);
	rt = ft_sqrt(nb);
	divider = 2;
	while (nb % divider && divider <= rt)
		divider ++;
	if (divider > rt)
		return (1);
	return (0);
}




int ft_sqrt(int nb)
{
	int	i;
	int	base;

	i = 1;
	if (nb < 0)
		return 0;
	while (nb > 1000000 * i * i && i < 47)
		i++;
	base = (i - 1) * 1000 - 1;
	if(base == 45999)
	{
		while (++base <= 46340)
			if(nb < base * base)
				return (base);
		return (46340);
	}
	while (++base <= i * 1000)
		if (nb < base * base)
			return (base);
	return (46340);
}

int ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return 2;
	while (ft_is_prime(nb) == 0 && nb < 2147483647)
		nb++;
	return (nb);
}
