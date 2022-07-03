/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:24:36 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/03 20:06:00 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	iter;

	iter = 0;
	while (s[iter] && s[iter] != '\n')
		iter++;
	return (iter);
}
