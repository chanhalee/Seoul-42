/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chahale@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 01:34:42 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/23 01:34:45 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		tower(int floor, int *arr);
void	find_empty(int index, int *arr, int *bowl);
void	build(int *tower);

int	ft_ten_queens_puzzle(void)
{
	int	arr[10];

	return (tower(0, arr));
}

int	tower(int floor, int *arr)
{
	int	bowl[10];
	int	localindex;
	int	returns;

	returns = 0;
	if (floor == 10)
	{
		build(arr);
		return (1);
	}
	find_empty(floor, arr, bowl);
	localindex = -1;
	while (++localindex < 10)
	{
		if (bowl[localindex] == -1)
			continue ;
		arr[floor] = bowl[localindex];
		returns += tower(floor + 1, arr);
	}
	return (returns);
}

void	find_empty(int index, int *arr, int *bowl)
{
	int	localindex;

	localindex = -1;
	while (++localindex < 10)
		bowl[localindex] = localindex;
	localindex = index;
	while (localindex-- > 0)
	{
		bowl[arr[localindex]] = -1;
		if (arr[localindex] + index - localindex < 10)
			bowl[arr[localindex] + index - localindex] = -1;
		if (arr[localindex] - index + localindex > -1)
			bowl[arr[localindex] - index + localindex] = -1;
	}
}

void	build(int *tower)
{
	int		floor;
	char	block;

	floor = -1;
	while (++floor < 10)
	{
		block = '0' + tower[floor];
		write(1, &block, 1);
	}
	write(1, "\n", 1);
}
