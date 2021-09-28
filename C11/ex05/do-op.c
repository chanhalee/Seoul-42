/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:57:06 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/28 20:12:16 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		c = 48 + (nb % 10) * -1;
		if ((nb / 10) * -1 > 0)
			ft_putnbr((nb / 10) * -1);
		write(1, &c, 1);
	}
	else
	{
		if (nb >= 10)
		{
			ft_putnbr(nb / 10);
		}
		c = 48 + nb % 10;
		write(1, &c, 1);
	}
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

int	ft_atoi(char *str)
{
	int	counter;
	int	minuscounter;
	int	result;

	result = 0;
	counter = 0;
	minuscounter = 0;
	str = removespace(str);
	while (str[counter] != '\0' && (str[counter] == '-'
			|| str[counter] == '+'))
		if (str[counter++] == '-')
			minuscounter++;
	if (minuscounter % 2 == 1)
		minuscounter = -1;
	else
		minuscounter = 1;
	while (str[counter] != '\0' && str[counter] >= '0'
		&& str[counter] <= '9')
	{
		result *= 10;
		result = result + (str[counter] - '0') * minuscounter;
		counter++;
	}
	return (result);
}
#include <stdio.h>
int main(int argc, char **argv)
{
	int	a;
	int	b;
	int flag;

	if (argc != 4)
		return (0);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	flag = 1;
	if (argv[2][0] == '/')
	{
		if (b == 0)
			write(1, "Stop : division by zero", 23);
		else
			ft_putnbr((a / b));
		flag = 0;
	}

	if(argv[2][0] == '%')
	{
		if(b == 0)
			write(1, "Stop : modulo by zero", 21);
		else
			ft_putnbr((a % b));
		flag = 0;
	}

	if(argv[2][0] == '*' && flag)
	{	
		printf("*");
		ft_putnbr((a * b));
		flag = 0;
	}
	if(argv[2][0] == '+' && flag)
	{
		ft_putnbr((a + b));
		flag = 0;
	}
	if(argv[2][0] == '-' && flag)
	{
		ft_putnbr((a - b));
		flag = 0;
	}
	if (flag)
		write(1, "0", 1);
	write(1, "\n", 1);
}
