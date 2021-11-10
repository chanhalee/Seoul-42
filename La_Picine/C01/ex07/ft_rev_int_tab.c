/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:07:23 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/15 15:24:12 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	size1;
	int	tempint;

	size1 = 0;
	tempint = 0;
	while (size1 < size / 2)
	{
		tempint = tab[size1];
		tab[size1] = tab[size - 1 - size1];
		tab[size - 1 - size1] = tempint;
		size1++;
	}
}
