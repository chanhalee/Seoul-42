/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:36:41 by chanhale          #+#    #+#             */
/*   Updated: 2022/02/06 15:26:32 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

int		deal_format(va_list *ap, char c);
int		int_form(va_list *ap);
int		uns_int_form(va_list *ap);
int		ft_printf(const char *str, ...);
int		char_form(va_list *ap);
int		str_form(va_list *ap);
void	un_putnb(unsigned int n, int fd);
void	ft_un_putnbr_fd(unsigned int n, int fd);
int		small_x_form(va_list *ap);
int		big_x_form(va_list *ap);
int		ft_put_ptr(uintptr_t nbr);
int		ft_puthex_fd(unsigned int nbr, int to_upper, int fd);
int		ptr_form(va_list *ap);
int		other_form(char c);

#endif
