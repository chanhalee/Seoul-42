/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:07:19 by chanhale          #+#    #+#             */
/*   Updated: 2021/11/10 16:14:16 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	casted_c;
	size_t	index;

	casted_c = (char) c;
	index = 0;
	while (s[index] != '\0')
		index++;
	while (index >= 0 && s[index] != casted_c)
		index--;
	if (s[index] == casted_c)
		return ((char *)s + index);
	return (0);
}
