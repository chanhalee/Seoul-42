/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chahale@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 01:42:23 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/28 01:47:22 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	int	local_index;

	local_index = -1;
	while (tab[++local_index] != 0)
		if ((*f)(tab[local_index]))
			return (1);
	return (0);
}
