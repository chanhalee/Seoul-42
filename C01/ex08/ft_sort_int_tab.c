/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:35:17 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/15 15:46:29 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp1;
	int	temp2;
	int	temp3;

	temp1 = 0;
	while (temp1 < size - 1)
	{
		temp2 = temp1 + 1;
		while (temp2 < size)
		{
			if (tab[temp2] > tab[temp1])
			{
				temp3 = tab[temp1];
				tab[temp1] = tab[temp2];
				tab[temp2] = temp3;
			}
			temp2++;
		}
		temp1++;
	}
}
