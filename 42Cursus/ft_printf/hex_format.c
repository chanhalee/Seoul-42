/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:22:42 by chanhale          #+#    #+#             */
/*   Updated: 2022/02/09 11:37:08 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	lower_form(va_list *ap)
{
	int				len;
	unsigned int	arg_x;

	arg_x = (unsigned int)va_arg(*ap, unsigned int);
	len = ft_puthex(arg_x, 0);
	return (len);
}

int	upper_form(va_list *ap)
{
	int				len;
	unsigned int	arg_x;

	arg_x = (unsigned int)va_arg(*ap, unsigned int);
	len = ft_puthex(arg_x, 1);
	return (len);
}

int	ft_puthex(unsigned int nbr, int is_it_upper)
{
	int	ret;

	ret = 0;
	if (nbr >= 16)
		ret += ft_puthex(nbr / 16, is_it_upper);
	if (is_it_upper)
	{
		ft_putchar_fd("0123456789ABCDEF"[nbr % 16], 1);
		ret++;
	}
	else
	{
		ft_putchar_fd("0123456789abcdef"[nbr % 16], 1);
		ret++;
	}
	return (ret);
}
