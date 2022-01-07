/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 23:25:58 by chanhale          #+#    #+#             */
/*   Updated: 2021/12/28 23:29:16 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
