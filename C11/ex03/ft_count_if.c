/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chahale@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 01:48:40 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/28 02:24:07 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	local_index;
	int	counter;

	local_index = -1;
	counter = 0;
	while (++local_index < length)
		if ((*f)(tab[local_index]))
			counter++;
	return (counter);
}
