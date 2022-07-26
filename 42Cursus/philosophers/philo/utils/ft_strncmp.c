/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:24:31 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/27 01:19:58 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	length_s1;
	size_t	iter;

	length_s1 = 0;
	iter = 0;
	while (s1[length_s1] != '\0')
		length_s1++;
	while (iter < length_s1 && iter < n - 1)
	{
		if (s1[iter] != s2[iter])
			break ;
		iter++;
	}
	if (n == 0)
		return (0);
	return (((unsigned char *)s1)[iter] - ((unsigned char *)s2)[iter]);
}
