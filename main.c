/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 23:10:21 by lch               #+#    #+#             */
/*   Updated: 2021/09/19 21:27:27 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>
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
int ft_atoi(char *str);
void makestring(char* str, char *d);

int	main(void)
{
	char d[200] = "     +-----+01201";
	int	i;
	i = ft_atoi(d);
	printf("%d", i);
	return 0;
}

void makestring(char* str, char *d){
	int temp = 0;
	
	while(str[temp] != '\0')
	{
		d[temp] = str[temp];
		temp++;
	}
}
