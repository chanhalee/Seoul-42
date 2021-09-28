/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chahale@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 23:43:13 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/29 00:24:35 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	tempint1;
	unsigned int	ti2;

	tempint1 = 0;
	ti2 = 0;
	while (s1[tempint1] != '\0')
		tempint1++;
	while (ti2 < tempint1)
	{
		if (s1[ti2] != s2[ti2])
			break ;
		ti2++;
	}
	tempint1 = ((unsigned char *)s1)[ti2] - ((unsigned char *)s2)[ti2];
	return (tempint1);
}

void	ft_sort_string_tab(char **tab)
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
			if (ft_strcmp(tab[index], tab[inner_index]) >= 0)
			{
				temp = tab[index];
				tab[index] = tab[inner_index];
				tab[inner_index] = temp;
			}
		}
	}
}
