/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:21:53 by chanhale          #+#    #+#             */
/*   Updated: 2022/02/06 15:26:18 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		ret;
	int		i;

	if (!str)
		return (-1);
	va_start(ap, str);
	i = 0;
	ret = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			ret += write(1, &str[i++], 1);
		else
		{
			i++;
			ret += deal_format(&ap, str[i++]);
		}
	}
	va_end(ap);
	return (ret);
}

int	deal_format(va_list *ap, char c)
{
	int	ret;

	if (c == 'd' || c == 'i')
		ret = int_form(ap);
	else if (c == 'u')
		ret = uns_int_form(ap);
	else if (c == 'x')
		ret = small_x_form(ap);
	else if (c == 'X')
		ret = big_x_form(ap);
	else if (c == 'c')
		ret = char_form(ap);
	else if (c == 's')
		ret = str_form(ap);
	else if (c == 'p')
		ret = ptr_form(ap);
	else
		ret = other_form(c);
	return (ret);
}

int	other_form(char c)
{
	if (c == '%')
		write(1, "%", 1);
	else if (ft_isascii(c))
		write(1, &c, 1);
	else
		return (0);
	return (1);
}
