/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chahale@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 01:50:15 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/28 02:19:45 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	local_index;
	int	prev;
	int	now;

	prev = 0;
	local_index = 0;
	while (++local_index < length)
	{
		now = (*f)(tab[local_index - 1], tab[local_index]);
		if ((now <= 0 && prev <= 0) || (now >= 0 && prev >= 0))
		{
			if (now != 0)
				prev = now;
		}
		else
			return (0);
	}
	return (1);
}
