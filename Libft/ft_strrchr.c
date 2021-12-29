/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:07:19 by chanhale          #+#    #+#             */
/*   Updated: 2021/12/29 15:07:42 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	casted_c;
	size_t	index;

	casted_c = (char) c;
	index = 0;
	if (s == NULL)
		return (NULL);
	while (s[index] != '\0')
		index++;
	if (index == 0)
	{
		if (c != '\0')
			return (0);
		else
			return ((char *)s);
	}
	while (index > 0 && s[index] != casted_c)
		index--;
	if (s[index] == casted_c)
		return ((char *)s + index);
	return (0);
}
