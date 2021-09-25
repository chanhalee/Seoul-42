/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chahale@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 15:07:16 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/25 17:05:45 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		checkbase(char *base);
int		ft_atoi_base(char *str, char *base);
void	ft_putnbr_base(int nbr, char *base, char **result);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char *result;
	int temp;
	if(!checkbase(base_from)||!checkbase(base_to))
		return (0);
	temp = ft_atoi_base(nbr, base_from);
	ft_putnbr_base(temp, base_to, &result);
	return (result);
}

int	parsechar(char c, char *base)
{
	int	index;

	index = 0;
	while (base[index])
	{
		if (base[index] == c)
			return (index);
		index++;
	}
	return (-1);
}

char	*removespace(char *s)
{
	int	c;

	c = 0;
	while ((s[c] == '\t' || s[c] == '\n' || s[c] == '\v'
			|| s[c] == '\f' || s[c] == '\r' || s[c] == ' ')
		&& s[c] != '\0')
		c++;
	return (s + c);
}

int	iterator_a(char *str, char *base, int result, int n)
{
	int	i;
	int	minus;

	minus = 1;
	if (n < 0)
		minus = -1;
	i = parsechar(str[0], base);
	if (i != -1)
	{
		result *= (n * minus);
		result += i * minus;
		minus = iterator_a(str + 1, base, result, n);
		return (minus);
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	counter;
	int	minuscounter;
	int	n;
	int	result;

	result = 0;
	counter = 0;
	minuscounter = 0;
	n = checkbase(base);
	if (n)
	{
		str = removespace(str);
		while (str[counter] != '\0' && (str[counter] == '-'
				|| str[counter] == '+'))
			if (str[counter++] == '-')
				minuscounter++;
		if (minuscounter % 2 == 1)
			minuscounter = -1;
		else
			minuscounter = 1;
		result = iterator_a(str + counter, base, 0, n * minuscounter);
	}
	return (result);
}
