/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semi_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:51:30 by chanhale          #+#    #+#             */
/*   Updated: 2022/02/09 12:00:34 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (fd < 0)
		return ;
	if (n < 0)
	{
		write(fd, "-", 1);
		c = 48 + (n % 10) * -1;
		if ((n / 10) * -1 > 0)
			ft_putnbr_fd((n / 10) * -1, fd);
		write(fd, &c, 1);
	}
	else
	{
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		c = 48 + n % 10;
		write(fd, &c, 1);
	}
}

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (s == NULL || fd < 0)
		return ;
	len = 0;
	while (s[len])
		len++;
	write(fd, s, len);
}
