/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:53:44 by chanhale          #+#    #+#             */
/*   Updated: 2021/11/10 16:54:20 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		size;
	int		localindex;
	char	*result;

	size = 0;
	while (src[size])
		size++;
	result = (char *)malloc((size + 1) * sizeof(char));
	localindex = -1;
	while (++localindex < size)
		result[localindex] = src[localindex];
	result[localindex] = '\0';
	return (result);
}
