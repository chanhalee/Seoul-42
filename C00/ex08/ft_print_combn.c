/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:31:51 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/16 03:37:46 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*subfunc(char *prev_arr, int num, int changenum);

void	ft_print_combn(int n)
{
	char	*result;
	int		tempa;
	char	arr[9];

	tempa = -1;
	while (tempa++ != n - 1)
	{
		arr[tempa] = tempa + 48;
	}
	result = arr;
	tempa = 0;
	while (arr[0] != '!')
	{
		if (tempa == 0)
		{
			tempa++;
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
