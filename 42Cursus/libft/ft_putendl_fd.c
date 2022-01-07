/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 23:17:59 by chanhale          #+#    #+#             */
/*   Updated: 2021/12/28 23:21:16 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;
	char	new_line;

	if (s == NULL || fd < 0)
		return ;
	len = 0;
	new_line = '\n';
	while (s[len])
		len++;
	write(fd, s, len);
	write(fd, &new_line, 1);
}
