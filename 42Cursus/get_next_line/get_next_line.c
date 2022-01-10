/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:10:02 by chanhale          #+#    #+#             */
/*   Updated: 2022/01/10 19:03:47 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char	*get_next_line(int fd)
{
	static char	*pending;
	char		*buffer;
	char		*result;
	size_t		complete_length;

	complete_length = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	result = read_data(fd, &pending, buffer);
	return (result);
}

char	*read_data(int fd, char **pending, char *buffer)
{
	int			ret;
	char		*char_ptr;
	t_length	len_data;

	if (pending && *pending && ft_my_strlen(*pending, &len_data))
	{
		buffer = ft_substr(*pending, 0, len_data.len);
		if (!buffer)
			return (NULL);
		char_ptr = ft_substr(*pending, len_data.len + 1, BUFFER_SIZE);
		free (*pending);
		*pending = char_ptr;
		return (buffer);
	}
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (read_data_subsidiary(fd, pending, &buffer))
		return (NULL);
	return (buffer);
}

int	read_data_subsidiary(int fd, char **pending, char **buffer)
{
	int			read_ret;
	char		*next_pending;
	t_length	len_data;

	if (!(*pending))
		*pending = ft_strjoin("","");
	read_ret = 1;
	while ((*pending) && !ft_my_strlen(*pending, &len_data) && read_ret)
	{
		read_ret = read(fd, *buffer, BUFFER_SIZE);
		if (read_ret < 0)
			break ;
		next_pending = ft_strjoin(*buffer, *pending);
		free (*pending);
		*pending = next_pending;
	}
	free (*buffer);
	if (!(*pending) || read_ret < 0)
		return (-1);
	*buffer = ft_substr(*pending, 0, len_data.len);
	//printf("%s||\n", *buffer);
	if (!(*buffer))
		return (-1);
	next_pending = ft_substr(*pending, len_data.len + 1, BUFFER_SIZE);
	free (*pending);
	*pending = next_pending;
	return (0);
}