/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:22:42 by chanhale          #+#    #+#             */
/*   Updated: 2022/02/06 15:26:12 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	small_x_form(va_list *ap)
{
	int				len;
	unsigned int	arg_x;

	arg_x = (unsigned int)va_arg(*ap, unsigned int);
	len = ft_puthex_fd(arg_x, 0, 1);
	return (len);
}

int	big_x_form(va_list *ap)
{
	int				len;
	unsigned int	arg_x;

	arg_x = (unsigned int)va_arg(*ap, unsigned int);
	len = ft_puthex_fd(arg_x, 1, 1);
	return (len);
}

int	ft_puthex_fd(unsigned int nbr, int to_upper, int fd)
{
	int	ret;

	ret = 0;
	if (nbr >= 16)
		ret += ft_puthex_fd(nbr / 16, to_upper, fd);
	if (to_upper)
	{
		ft_putchar_fd("0123456789ABCDEF"[nbr % 16], fd);
		ret++;
	}
	else
	{
		ft_putchar_fd("0123456789abcdef"[nbr % 16], fd);
		ret++;
	}
	return (ret);
}
