/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:45:01 by chanhale          #+#    #+#             */
/*   Updated: 2021/12/30 20:01:50 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*allocated;
	unsigned int	index;

	if (s == NULL)
		return (NULL);
	allocated = (char *)malloc(sizeof(char) * (len + 1));
	if (allocated == NULL)
		return (NULL);
	index = -1;
	*allocated = '\0';
	while (++index <= start)
		if (s[index] == '\0')
			return (allocated);
	index = 0;
	while (index < len && s[start])
	{
		allocated[index] = s[start];
		start++;
		index++;
	}
	allocated[index] = '\0';
	return (allocated);
}
