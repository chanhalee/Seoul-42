/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:10:29 by chanhale          #+#    #+#             */
/*   Updated: 2021/12/29 12:39:20 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_arr_size(char const *s, char c);
static char		*make_elements(char const **s, char c);

char	**ft_split(char const *s, char c)
{
	char	**result;
	char	**iter_result;
	char	*element;
	size_t	arr_size;

	arr_size = get_arr_size(s, c);
	result = (char **)malloc(sizeof(char *) * arr_size);
	if (result == NULL)
		return (NULL);
	iter_result = result;
	while (--arr_size)
	{
		element = make_elements(&s, c);
		if (element == NULL)
			return (NULL);
		*(iter_result++) = element;
	}
	*iter_result = NULL;
	return (result);
}

static size_t	get_arr_size(char const *s, char c)
{
	size_t	result;
	int		flag;

	result = 1;
	flag = 0;
	while (*s)
	{
		if (*s == c)
		{
			if (flag)
			{
				result++;
				flag = 0;
			}
		}
		else
			flag = 1;
		s++;
	}
	if (flag)
		result++;
	return (result);
}

static char	*make_elements(char const **s, char c)
{
	size_t		size;
	char		*result;
	char const	*iter_s;
	char		*iter_result;

	size = 1;
	while (**s == c)
		(*s)++;
	iter_s = *s;
	while (**s != c && **s != '\0')
	{
		size++;
		(*s)++;
	}
	result = (char *)malloc(sizeof(char) * size);
	iter_result = result;
	if (iter_result == NULL)
		return (NULL);
	while (*iter_s != c && *iter_s != '\0')
		*(iter_result++) = *(iter_s++);
	*iter_result = '\0';
	return (result);
}
