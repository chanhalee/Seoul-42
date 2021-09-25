/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chahale@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:58:05 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/25 19:07:19 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_split_s(char *str, char *charset, char** result, int where_s);

char interpret(char let, char *sep)
{
	int	local_index;

	local_index = -1;
	while (sep[++local_index])
		if (let == sep[local_index])
			return (0);
	return (let);
}

char	 **ft_split(char *str, char *charset)
{
	char	**result;
	int		local_index;
	int		length;

	local_index = 0;
	length = 0;
	while (str[local_index])
	{
		if (interpret(str[local_index], charset) && ++length)
			while (str[local_index] && interpret(str[local_index], charset))
				local_index++;
		else
			while (str[local_index] && !interpret(str[local_index], charset))
				local_index++;
	}
	result = (char **)malloc(sizeof(char*) * length + 1);
	result[length] = NULL;
	ft_split_s(str, charset, result, 0);
	return (result);
}

void	ft_split_s(char *str, char *charset, char** result, int where_s)
{
	int		end;
	int		start;
	int 	where;

	where = 0;
	start = 0;
	end = 0;
	while (str[end])
	{
		if (interpret(str[end], charset))
		{
			where_s = 0;
			while (str[end] && interpret(str[end], charset))
				end++;
			result[where] = (char *)malloc(sizeof(char) * (end - start + 1));
			while (start != end)
				result[where][where_s++] = str[start++];
			result[where++][where_s] = '\0';
		}
		else
			while (str[end] && !interpret(str[end], charset))
				end++;
		start = end;
	}
}

