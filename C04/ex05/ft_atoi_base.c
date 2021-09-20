/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chahale@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 02:03:57 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/21 03:05:54 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	iterator(char *str, char *base, int result, int n)
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
		minus = iterator(str + 1, base, result, n);
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
		result = iterator(str + counter, base, 0, n * minuscounter);
	}
	return (result);
}
