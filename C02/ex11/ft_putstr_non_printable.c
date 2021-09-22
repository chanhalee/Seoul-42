/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahale <chahale@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 20:42:24 by chahale           #+#    #+#             */
/*   Updated: 2021/09/19 15:13:13 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	parse(char c, char	*result);

void	ft_putstr_non_printable(char *str)
{
	int		temp;
	char	c;
	char	k[4];

	temp = 0;
	while (str[temp] != '\0')
	{
		c = str[temp];
		if ((c >= 32 && c <= 126))
			write(1, &c, 1);
		else
		{
			parse(c, k);
			write(1, k, 3);
		}
		temp++;
	}
}

void	parse(char c, char	*result)
{
	unsigned char	cu;

	cu = (unsigned char)c;
	result[0] = '\\';
	if (cu / 16 < 10)
		result[1] = 48 + cu / 16;
	else
		result[1] = 87 + cu / 16;
	if (cu % 16 < 10)
		result[2] = 48 + cu % 16;
	else
		result[2] = 87 + cu % 16;
}
