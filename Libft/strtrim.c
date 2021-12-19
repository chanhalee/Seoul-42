/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:10:28 by chanhale          #+#    #+#             */
/*   Updated: 2021/12/19 15:14:30 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*subfunc(const char *s1, const char *set, char **result);

char	*ft_strtrim(char const *s1, char const *set)
{
	int			flag;
	char		*result;
	char		*iter_result;
	const char	*iter_set;

	result = NULL;
	if(s1 == NULL || set == NULL || !subfunc(s1, set, &result))
		return (NULL);
	iter_result = result;
	while (*s1)
	{
		iter_set = set;
		flag = 1;
		while (*iter_set)
			if (*(s1) == *(iter_set++))
			{
				flag = 0;
				break ;
			}
		if (flag)
			*(iter_result++) = *s1;
		s1++;
	}
	return (result);
}

static char	*subfunc(const char *s1, const char *set, char **result)
{
	const char	*iter_s1;
	const char	*iter_set;
	size_t		size;

	iter_s1 = s1;
	iter_set = set;
	size = 1;
	while (*iter_s1){
		iter_set = set;
		while (*iter_set)
			if (*(iter_s1) == *(iter_set++))
			{
				size--;
				break ;
			}
		size++;
		iter_s1++;
	}
	*result = (char*)malloc(size * sizeof(char));
	if (*result != NULL)
		*(*result + size -1) = '\0';
	return (*result);
}
