/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:23:46 by chanhale          #+#    #+#             */
/*   Updated: 2022/02/06 15:26:09 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_form(va_list *ap)
{
	int	arg_int;
	int	ret;

	arg_int = (int)va_arg(*ap, int);
	ft_putnbr_fd(arg_int, 1);
	ret = 0;
	if (arg_int == 0)
		ret += 1;
	else if (arg_int < 0)
	{
		arg_int *= -1;
		ret += 1;
	}
	while (arg_int)
	{
		arg_int /= 10;
		ret++;
	}
	return (ret);
}

int	uns_int_form(va_list *ap)
{
	unsigned int	arg_int;
	int				ret;

	arg_int = (unsigned int)va_arg(*ap, int);
	ft_un_putnbr_fd(arg_int, 1);
	ret = 0;
	if (arg_int == 0)
		ret += 1;
	else if (arg_int < 0)
	{
		arg_int *= -1;
		ret += 1;
	}
	while (arg_int)
	{
		arg_int /= 10;
		ret++;
	}
	return (ret);
}

void	un_putnb(unsigned int n, int fd)
{
	if (n >= 10)
	{
		un_putnb(n / 10, fd);
		ft_putchar_fd('0' + (n % 10), fd);
	}
	else
		ft_putchar_fd('0' + n, fd);
}

void	ft_un_putnbr_fd(unsigned int n, int fd)
{
	if (fd < 0)
		return ;
	un_putnb(n, fd);
}
