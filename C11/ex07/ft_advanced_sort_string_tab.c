/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chahale@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 00:12:19 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/29 00:24:07 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		index;
	int		inner_index;
	char	*temp;

	index = -1;
	while (tab[++index] != NULL)
	{
		inner_index = index;
		while (tab[++inner_index] != NULL)
		{
			if ((*cmp)(tab[index], tab[inner_index]) >= 0)
			{
				temp = tab[index];
				tab[index] = tab[inner_index];
				tab[inner_index] = temp;
			}
		}
	}
}
