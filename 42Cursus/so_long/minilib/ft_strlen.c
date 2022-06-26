/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:24:36 by chanhale          #+#    #+#             */
/*   Updated: 2022/06/26 22:45:09 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	iter;

	iter = 0;
	while (s[iter])
		iter++;
	return (iter);
}
