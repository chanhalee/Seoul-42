/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:13:25 by chanhale          #+#    #+#             */
/*   Updated: 2022/03/08 23:53:25 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <signal.h>

# define TYPE_PARSE_ERROR -2147483648
# define TYPE_SEND_FAIL 1
# define TYPE_SEND_SUCCESS 0

typedef struct s_infobox
{
	int			counter;
	int			character;
	pid_t		client_id;
}	t_infobox;

typedef struct s_client_data
{
	char		*msg;
	size_t		index;
	int			bit;
	pid_t		server_pid;
}	t_client_data;

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
int		ft_atoi_custom(char *str);

#endif