/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:45:01 by chanhale          #+#    #+#             */
/*   Updated: 2021/12/03 13:58:37 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*allocated;
	char			*result;
	unsigned int	s_offset;

	allocated = (char *)malloc(sizeof(char) * len);
	if (!allocated || len == 0)
		return (NULL);
	result = allocated;
	s_offset = -1;
	while (*(s + start) && --len)
	{
		*allocated = *(s + start);
		++s;
		++allocated;
	}
	return (result);
}
