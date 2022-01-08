/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:10:02 by chanhale          #+#    #+#             */
/*   Updated: 2022/01/09 01:43:17 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*result;
	size_t		complete_length;

	complete_length = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!buffer)
	{
		buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		*buffer = '\0';
	}
	else
		complete_length = search_new_line_char(buffer);
	if (complete_length)
		result = buf_has_all(&buffer, complete_length);
	else
		result = buf_incomplete(fd, &buffer);
	return (result);
}

size_t	search_new_line_char(char *buffer)
{
	size_t	length;

	length = 0;
	while (++length && buffer[length - 1])
		if (buffer[length -1] == '\n')
			return (length);
	return (0);
}

char	*buf_has_all(char **buffer, size_t length)
{
	char	*result;
	char	*next_gen_buffer;

	result = ft_substr(*buffer, 0, length - 1);
	if (!result)
		return (NULL);
	next_gen_buffer = ft_substr(*buffer, length, BUFFER_SIZE);
	free (*buffer);
	*buffer = next_gen_buffer;
	return (result);
}

char	*buf_incomplete(int fd, char **buffer)
{
	char	*result;
	char	*next_gen;
	int		length;

	result = ft_strdup(*buffer);
	if (!result)
		return (NULL);
	while (!search_new_line_char(*buffer))
	{
		length = read(fd, *buffer, BUFFER_SIZE);
		if (length == 0)
			break ;
		if (length < 0)
			free (result);
		if (length < 0)
			return (0);
		next_gen = ft_strjoin(result, *buffer);
		free(result);
		if (!next_gen)
			return (NULL);
		result = next_gen;
	}
	next_gen = NULL;
	if (search_new_line_char(*buffer))
		next_gen = ft_substr(*buffer, search_new_line_char(*buffer), BUFFER_SIZE);
	free (*buffer);
	*buffer = next_gen;
	return (result);
}