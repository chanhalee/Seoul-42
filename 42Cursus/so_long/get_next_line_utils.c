/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:09:52 by chanhale          #+#    #+#             */
/*   Updated: 2022/06/27 20:06:37 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./so_long.h"

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

int	ft_my_strlen(const char *s, t_length *result)
{
	size_t		iter;

	iter = 0;
	if (!s)
	{
		(*result).type = TYPE_NULL;
		(*result).len = 0;
		return (TYPE_NULL);
	}
	while (s[iter] && s[iter] != '\n')
		iter++;
	if (s[iter])
		(*result).type = TYPE_NEW_LINE;
	else
		(*result).type = TYPE_NULL;
	(*result).len = iter;
	return ((*result).type);
}

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
	*iter_result = '\0';
	return (result);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	write_val;
	size_t			iter;
	unsigned char	*casted_b;

	iter = 0;
	casted_b = (unsigned char *)b;
	write_val = (unsigned char) c;
	while (iter < len)
		casted_b[iter++] = write_val;
	return (b);
}
