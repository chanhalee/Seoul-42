/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_costom.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:41:01 by chanhale          #+#    #+#             */
/*   Updated: 2022/03/08 22:56:09 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static char	*removespace(char *s);

int	ft_atoi_custom(char *str)
{
	long long	counter;
	long long	result;

	result = 0;
	counter = 0;
	str = removespace(str);
	if (str[counter] != '\0' && (str[counter] == '-'
			|| str[counter] == '+'))
		if (str[counter++] == '-')
			return (TYPE_PARSE_ERROR);
	while (str[counter] != '\0')
	{
		if (str[counter] < '0' || str[counter] > '9')
			return (TYPE_PARSE_ERROR);
		result *= (long long) 10;
		result += (long long)((str[counter] - '0'));
		counter++;
		if (2147483647 < result || result < 0)
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
