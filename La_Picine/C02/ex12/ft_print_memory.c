/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:51:55 by chahale           #+#    #+#             */
/*   Updated: 2021/09/23 13:24:25 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_print_memory(void *addr, unsigned int size);
void	parsenprintaddress(unsigned long addr);
void	printrest(char	*addr, int size);
void	parsenprintchar(char c, int type);
char	parsehexa(int num);

void	*ft_print_memory(void *addr, unsigned int size)
{
	char	*data;

	data = (char *)addr;
	while (size >= 16)
	{
		parsenprintaddress((unsigned long)data);
		printrest(data, 16);
		size -= 16;
		data += 16;
	}
	if (size > 0)
	{
		parsenprintaddress((unsigned long)addr);
		printrest(data, size);
	}
	return (addr);
}

void	parsenprintaddress(unsigned long addr)
{
	int				temp1;
	unsigned long	copy;
	char			parseresult[18];

	temp1 = -1;
	copy = addr;
	while (++temp1 != 16)
		parseresult[temp1] = '0';
	while (copy > 0)
	{
		parseresult[--temp1] = parsehexa(copy % 16);
		copy = copy / 16;
	}
	parseresult[16] = ':';
	parseresult[17] = ' ';
	write(1, parseresult, 18);
}

void	printrest(char	*addr, int size)
{
	int		temp1;

	temp1 = 0;
	while (temp1 < size - 1)
	{
		parsenprintchar(addr[temp1], 1);
		parsenprintchar(addr[temp1 + 1], 1);
		write(1, " ", 1);
		temp1 += 2;
	}
	if (size % 2 == 1)
	{
		parsenprintchar(addr[temp1 - 2], 1);
		write(1, "   ", 3);
	}
	temp1 = (16 - size) / 2;
	while (temp1-- > 0)
		write(1, "     ", 5);
	temp1 = -1;
	while (++temp1 < size)
	{
		parsenprintchar(addr[temp1], 2);
	}
	write(1, "\n", 1);
}

void	parsenprintchar(char c, int type)
{
	char	a;
	char	b;

	if (type == 1)
	{
		a = parsehexa(c % 16);
		c = c / 16;
		b = parsehexa(c % 16);
		write(1, &b, 1);
		write(1, &a, 1);
	}
	else
	{
		if (c >= 32 && c <= 126)
			write(1, &c, 1);
		else
			write(1, ".", 1);
	}
}

char	parsehexa(int num)
{
	if (num < 10)
		return (num + 48);
	else
		return (num + 87);
}
