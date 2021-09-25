/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 23:10:21 by lch               #+#    #+#             */
/*   Updated: 2021/09/26 03:00:24 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_stock_str.h"


//C03
//int ft_strcmp(char *s1, char *s2);//1
//int ft_strncmp(char *s1, char *s2, unsigned int n);//2
//char *ft_strcat(char *dest, char *src);//3
//char *ft_strncat(char *dest, char *src, unsigned int nb);
//char *ft_strstr(char *str, char *to_find);
//unsigned int ft_strlcat(char *dest, char *src, unsigned int size);
//--
//C04
//void ft_putstr(char *str);
//void ft_putnbr(int nb);
//int ft_atoi(char *str);
//void ft_putnbr_base(int nbr, char *base);
int ft_atoi_base(char *str, char *base);
//C05
int ft_iterative_factorial(int nb);
//int ft_ten_queens_puzzle(void);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int ft_recursive_factorial(int nb);
int ft_is_prime(int nb);
char	*ft_strjoin(int size, char **strs, char *sep);
int *ft_range(int min, int max);
char *ft_convert_base(char *nbr, char *base_from, char *base_to);
void				ft_show_tab(struct s_stock_str *par);

int		main(void)
{
	char *av1[] = { "HelloWorld!" };
	

}





//C02
//char *ft_strcpy(char *dest, char *src);
//char *ft_strncpy(char *dest, char *src, unsigned int n);
//int ft_str_is_alpha(char *str);
//int ft_str_is_numeric(char *str);
//int ft_str_is_lowercase(char *str);
//unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);//
//char *ft_strcapitalize(char *str);
//unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);
//void ft_putstr_non_printable(char *str);//11
//void *ft_print_memory(void *addr, unsigned int size);
