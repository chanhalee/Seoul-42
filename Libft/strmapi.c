/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmapi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 01:52:24 by chanhale          #+#    #+#             */
/*   Updated: 2021/12/28 02:12:09 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char const		*iter_s;
	char			*result;

	if (s == NULL || f == NULL)
		return (NULL);
	len = 1;
	iter_s = s;
	while (*(iter_s++))
		len++;
	result = malloc(sizeof(char) * len);
	if (result == NULL)
		return (NULL);
	len = -1;
	while (s[++len])
		result[len] = f(len, s[len]);
	result[len] = '\0';
	return (result);
}
