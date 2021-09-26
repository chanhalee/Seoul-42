/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chahale@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 00:50:34 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/26 11:28:33 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		assume_len(int size, char **strs, char *sep);
char	*ft_strcat(char *dest, char *src);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		len;

	if (size > 0)
		len = assume_len(size, strs, sep);
	else	
		len = 1;
	result = (char *)malloc(sizeof(char) * len);
	while (--len >= 0)
		result[len] = '\0';
	if (size <= 0)
		return (result);
	len = -1;
	while (++len < size - 1)
	{
		ft_strcat(result, strs[len]);
		ft_strcat(result, sep);
	}
	ft_strcat(result, strs[len]);
	return (result);
}

int	assume_len(int size, char **strs, char *sep)
{
	int	result;
	int	indexa;
	int	indexb;

	if (size <= 0)
		return (1);
	result = 0;
	indexa = -1;
	while (++indexa < size)
	{
		indexb = -1;
		while (strs[indexa][++indexb])
			result++;
	}
	indexa = 0;
	while (sep[indexa])
		indexa++;
	result += indexa * (size - 1) + 1;
	return (result);
}

char	*ft_strcat(char *dest, char *src)
{
	int	destlength;
	int	srclength;

	srclength = 0;
	destlength = 0;
	while (dest[destlength] != '\0')
		destlength++;
	while (src[srclength] != '\0')
	{
		dest[destlength + srclength] = src[srclength];
		srclength++;
	}
	dest[destlength + srclength] = '\0';
	return (dest);
}
