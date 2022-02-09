/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:21:53 by chanhale          #+#    #+#             */
/*   Updated: 2022/02/09 12:35:09 by chanhale         ###   ########.fr       */
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
			ret += forge(&ap, str[i++]);
		}
	}
	va_end(ap);
	return (ret);
}

int	forge(va_list *ap, char c)
{
	int	ret;

	ret = 0;
	if (c == 'd' || c == 'i')
		ret = int_form(ap);
	else if (c == 'u')
		ret = uns_int_form(ap);
	else if (c == 'x')
		ret = lower_form(ap);
	else if (c == 'X')
		ret = upper_form(ap);
	else if (c == 'c')
		ret = char_form(ap);
	else if (c == 's')
		ret = str_form(ap);
	else if (c == 'p')
		ret = ptr_form(ap);
	else if (c == '%')
		ret = write(1, "%", 1);
	return (ret);
}
