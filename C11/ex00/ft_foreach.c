/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chahale@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 01:12:22 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/28 01:19:32 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	local_index;

	local_index = -1;
	while (++local_index < length)
		(*f)(tab[local_index]);
}
