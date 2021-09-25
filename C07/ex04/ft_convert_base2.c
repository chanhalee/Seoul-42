/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chahale@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 15:15:14 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/25 17:20:43 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	iterator(int i, int n, char *base, char **result);
int		checkbase(char *base);
void	count(int i, int n, char *base, int *result);

void	ft_putnbr_base(int nbr, char *base_to, char **result)
{
	int		n;
	int 	size;
	char	*copy;

	size = 0;
	n = checkbase(base_to);
	if (n)
	{
		count(nbr, n, base_to, &size);
		*result = (char *)malloc(sizeof (char) * ++size);
		copy = *result;
		iterator(nbr, n, base_to, &copy);
		(*result)[size-1] = '\0';
	}
}

void	iterator(int i, int n, char *base, char **result)
{
	char	c;

	if (i < 0)
	{
		**result = '-';
		(*result)++;
		c = base[((i % n) * -1)];
		if ((i / n) * -1 > 0)
			iterator((i / n) * -1, n, base, result);
		**result = c;
		(*result)++;
	}
	else
	{
		if (i >= n)
		{
			iterator(i / n, n, base, result);
		}
		**result =  *(base + i % n);
		(*result)++;
	}
}

void	count(int i, int n, char *base, int *result)
{
	if (i < 0)
	{
		(*result)++;
		if ((i / n) * -1 > 0)
			count((i / n * -1), n, base, result);
		(*result)++;
	}
	else
	{
		if (i >= n)
		{
			count(i / n, n, base, result);
		}
		(*result)++;
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
