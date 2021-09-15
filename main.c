/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 23:10:21 by lch               #+#    #+#             */
/*   Updated: 2021/09/15 21:47:38 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_putstr_non_printable(char *str);
void makestring(char* str, char *d);
int	main(void)
{
	// char tap[27];
	// for(int i = 0; i < 26 ; i++){
	// 	tap[i] = i+65;
	// }
	// tap[9] = '!';
	// printf("%s\n", tap);
	char d[200];
	makestring("Vonjure ?  ", d);
	d[0] = '0';
	d[1] = '1';
	d[2] = '\n';
	//d[10] = '\n';
	ft_putstr_non_printable(d);
	//printf("%s \n", d);
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