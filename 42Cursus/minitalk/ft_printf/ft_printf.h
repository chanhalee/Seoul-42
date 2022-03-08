/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:36:41 by chanhale          #+#    #+#             */
/*   Updated: 2022/02/09 12:08:09 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		forge(va_list *ap, char c);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_isascii(int c);
int		int_form(va_list *ap);
int		uns_int_form(va_list *ap);
int		ft_printf(const char *str, ...);
int		char_form(va_list *ap);
int		str_form(va_list *ap);
void	un_putnbr(unsigned int n);
int		lower_form(va_list *ap);
int		upper_form(va_list *ap);
int		ft_put_ptr(uintptr_t nbr);
int		ft_puthex(unsigned int nbr, int is_it_upper);
int		ptr_form(va_list *ap);
int		other_form(char c);

#endif
