/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:57:26 by chanhale          #+#    #+#             */
/*   Updated: 2021/12/30 20:28:23 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	index_result;
	unsigned int	index_str;
	char			*result;
	char			*iter_result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	index_result = 0;
	index_str = 0;
	while (*(s1 + index_result))
		index_result++;
	while (*(s2 + index_str))
		index_str++;
	index_result += (index_str + 1);
	result = (char *)malloc(sizeof(char) * index_result);
	if (result == NULL)
		return (NULL);
	iter_result = result;
	while (*s1)
		*(iter_result++) = *(s1++);
	while (*s2)
		*(iter_result++) = *(s2++);
	*iter_result = 0x00;
	return (result);
}
