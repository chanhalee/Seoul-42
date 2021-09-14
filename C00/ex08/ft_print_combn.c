/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:31:51 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/14 20:16:05 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
char	*subfunc(char *prev_arr, int num, int changenum);

void	ft_print_combn(int n)
{
	char	*result;
	int		tempA;
	char	arr[9];

	tempA = -1;
	while (tempA++ != n - 1)
	{
		arr[tempA] = tempA + 48;
	}
	result = arr;
	write (1, result, n);
	tempA = 0;
	while (arr[0] != '!')
	{
		if (tempA != 0)
		{
			tempA++;
		}
		else
		{
			write(1, ", ", 2);
		}
		write(1, result, n);
		result = subfunc(result, n, n);
	}
}

char	*subfunc(char	*prev_arr, int num, int changenum)
{
	if (changenum == 0)
	{
		prev_arr[changenum] = '!';
		return (prev_arr);
	}
	if (prev_arr[changenum - 1] == '9' - (num - changenum))
	{
		subfunc(prev_arr, num, changenum - 1);
	}
	else
	{
		prev_arr[changenum - 1] += 1;
		while (changenum != num)
		{
			prev_arr[changenum] = prev_arr[changenum - 1] + 1;
			changenum++;
		}
	}
	return (prev_arr);
}
