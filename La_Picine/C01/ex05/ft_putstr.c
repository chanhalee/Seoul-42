/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 02:18:32 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/16 02:32:02 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	temp;

	temp = 0;
	while (str[temp] != '\0')
	{
		temp++;
	}
	write(1, str, temp);
}
