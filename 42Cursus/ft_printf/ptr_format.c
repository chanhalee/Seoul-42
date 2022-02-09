/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:24:12 by chanhale          #+#    #+#             */
/*   Updated: 2022/02/09 11:38:35 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptr_form(va_list *ap)
{
	int			len;
	uintptr_t	ptr;

	len = 0;
	ptr = (uintptr_t)va_arg(*ap, uintptr_t);
	write(1, "0x", 2);
	len += 2;
	if (ptr == 0)
	{
		ft_putchar_fd('0', 1);
		len++;
	}
	else
		len += ft_put_ptr(ptr);
	return (len);
}

int	ft_put_ptr(uintptr_t nbr)
{
	int	ret;

	ret = 0;
	if (nbr >= 16)
	{
		ret += ft_put_ptr (nbr / 16);
		ret += ft_put_ptr (nbr % 16);
	}
	else
	{
		ft_putchar_fd("0123456789abcdef"[nbr % 16], 1);
		ret++;
	}
	return (ret);
}
