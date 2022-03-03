/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll_costom.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lch <lch@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:41:01 by chanhale          #+#    #+#             */
/*   Updated: 2022/03/03 13:49:05 by lch              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*removespace(char *s);

long long	ft_atoll(char *str)
{
	long long	counter;
	long long	minuscounter;
	long long	result;

	result = 0;
	counter = 0;
	minuscounter = (long long) 1;
	str = removespace(str);
	if (str[counter] != '\0' && (str[counter] == '-'
			|| str[counter] == '+'))
		if (str[counter++] == '-')
			minuscounter = (long long) -1;
	while (str[counter] != '\0')
	{
		if (str[counter] < '0' || str[counter] > '9')
			return (TYPE_PARSE_ERROR);
		result *= (long long) 10;
		result += (long long)((str[counter] - '0') * (minuscounter));
		counter++;
		if (2147483647 < result || result < -2147483648)
			return (TYPE_PARSE_ERROR);
	}
	return (result);
}

static char	*removespace(char *s)
{
	int	c;

	c = 0;
	while ((s[c] == '\t' || s[c] == '\n' || s[c] == '\v'
			|| s[c] == '\f' || s[c] == '\r' || s[c] == ' ')
		&& s[c] != '\0')
		c++;
	return (s + c);
}
