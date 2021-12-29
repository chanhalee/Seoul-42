/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:41:01 by chanhale          #+#    #+#             */
/*   Updated: 2021/12/29 11:04:25 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*removespace(char *s);

int	ft_atoi(char *str)
{
	int	counter;
	int	minuscounter;
	int	result;

	result = 0;
	counter = 0;
	minuscounter = 1;
	str = removespace(str);
	if (str[counter] != '\0' && (str[counter] == '-'
			|| str[counter] == '+'))
		if (str[counter++] == '-')
			minuscounter = -1;
	while (str[counter] != '\0' && str[counter] >= '0'
		&& str[counter] <= '9')
	{
		result *= 10;
		result = result + (str[counter] - '0') * minuscounter;
		counter++;
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
