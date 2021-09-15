/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:51:55 by chahale           #+#    #+#             */
/*   Updated: 2021/09/16 00:19:30 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
void	*ft_print_memory(void *addr, unsigned int size);
void	parsenprintaddress(unsigned long	addr);
void	printrest(char	*addr, int size);
void 	parsenprintchar(char c);
char	parsehexa(int num);
void	checknwrite(char c);

void makestring(char* str, char *d){
	int temp = 0;
	
	while(str[temp] != '\0')
	{
		d[temp] = str[temp];
		temp++;
	}
}

int main(void){
	char d[200];
	makestring("fdhsakd daldkfjla.dsfd.sk kdh!dk ndsk@@#!FQAFADdadfasdfasdfasdfasdasdasAEefsfklajfksl ", d);
	d[30] = '\n';
	d[59] = '\0';
	ft_print_memory(&d, 60);
	return 0;
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char	*data;
	int		temp1;

	data = (char	*)addr;
	while(size >= 16)
	{
		parsenprintaddress((unsigned long)data);
		printrest(data, 16);
		size -= 16;
		data += 16;
	}
	if(size > 0)
	{
		parsenprintaddress((unsigned long)addr);
		printrest(data, size);
	}

	return (addr);
}
void	parsenprintaddress(unsigned long	addr)
{
	int	temp1;
	unsigned long copy;
	char	parseresult[18];

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
	char	data;
	
	temp1 = 0;
	while (temp1 < size -1)
	{
		parsenprintchar(addr[temp1]);
		parsenprintchar(addr[temp1+1]);
		write(1, " ", 1);
		temp1 += 2;
	}
	if(size % 2 == 1)
	{
		parsenprintchar(addr[temp1-2]);
		write(1, "                           ", 32-size*2);
	}
	temp1 = -1;
	while (++temp1 < size)
	{
		checknwrite(addr[temp1]);
	}
	write	(1, "\n", 1);
}

void 	parsenprintchar(char c)
{
	char	a;
	char	b;

	a = parsehexa	(c % 16);
	c = c / 16;
	b = parsehexa	(c % 16);
	write	(1, &b, 1);
	write	(1, &a, 1);
}

char	parsehexa(int num)
{
	if(num < 10)
		return (num + 48);
	else
		return (num + 87);
}

void	checknwrite(char c)
{
	if(c >= 32 && c <= 126)
		write(1, &c, 1);
	else
		write(1, ".", 1);
}