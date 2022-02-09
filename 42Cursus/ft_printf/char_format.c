/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:20:54 by chanhale          #+#    #+#             */
/*   Updated: 2022/02/09 11:36:20 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	char_form(va_list *ap)
{
	char	arg_char;
	int		ret;

	arg_char = (char)va_arg(*ap, int);
	write(1, &arg_char, 1);
	ret = 1;
	return (ret);
}

int	str_form(va_list *ap)
{
	char	*str;
	int		ret;

	str = (char *)va_arg(*ap, char *);
	ret = 0;
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (str[ret])
	{
		ft_putchar_fd(str[ret], 1);
		ret++;
	}
	return (ret);
}
