/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:10:28 by chanhale          #+#    #+#             */
/*   Updated: 2021/12/03 19:01:32 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		result_size;
	char		*result;
	char		*iter_str;
	char const	*iter_set;

	result_size = 1;
	iter_s1 = s1;
	while (*(++iter_s1 - 1))
	{
		iter_str = set;
		while (*(iter_str++) != *(iter_s1 - 1))
			if (*iter_str == '\0')
				result_size++;
	}
	if ((result = (char *)malloc(sizeof (char) * result_size)))
		return (NULL);
	iter_result = result;
	while (*(++s1 - 1))
	{
		iter_str = set;
		while (*(iter_str++) != *(s1 - 1))
			if (*iter_str == '\0')
				*(iter_result++) = *(s1 - 1);
	}
	return (result);
}
