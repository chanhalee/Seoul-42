/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:52:23 by chanhale          #+#    #+#             */
/*   Updated: 2021/12/29 00:07:37 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	alloc_space(int nbr, char **result, char **iter);
static void	iter(int nb, char **result);

char	*ft_itoa(int n)
{
	char	*result;
	char	*iter_result;

	if (alloc_space(n, &result, &iter_result))
		return (NULL);
	iter(n, &iter_result);
	return (result);
}

static int	alloc_space(int nbr, char **result, char **iter)
{
	int	i;

	i = 1;
	if (nbr < 0)
	{
		i++;
		nbr = nbr * -1;
	}
	while (nbr > 9)
	{
		nbr /= 10;
		i++;
	}
	*result = (char *)malloc(sizeof(char) * (i + 1));
	*iter = *result;
	if (iter == NULL || result == NULL)
		return (1);
	return (0);
}

static void	iter(int nb, char **result)
{
	char	c;

	if (nb < 0)
	{
		*(*result++) = '-';
		c = 48 + (nb % 10) * -1;
		if ((nb / 10) * -1 > 0)
			iter((nb / 10) * -1, result);
		*(*result++) = c;
	}
	else
	{
		if (nb >= 10)
			iter(nb / 10, result);
		*(*result++) = 48 + nb % 10;
	}
}
