/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chahale@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 01:33:28 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/26 03:12:15 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int		ft_strdup(char *src, t_stock_str *bowl);
void	emergency_exit(int index, t_stock_str *result);

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*result;
	int			local_index;
	int			emergency;

	emergency = 0;
	local_index = -1;
	if (ac < 0)
		return (NULL);
	result = (t_stock_str *)malloc(sizeof (t_stock_str) * (ac + 1));
	if (result == NULL)
		return (NULL);
	while (++local_index < ac && !emergency)
		emergency = ft_strdup(av[local_index], &result[local_index]);
	if (emergency)
	{
		emergency_exit(local_index, result);
		return (NULL);
	}
	result[local_index].str = NULL;
	result[local_index].copy = NULL;
	return (result);
}	

int	ft_strdup(char *src, t_stock_str *bowl)
{
	int		size;
	int		local_index;
	char	*result;

	size = 0;
	while (src[size])
		size++;
	result = (char *)malloc((size + 1) * sizeof(char));
	if (result == NULL)
		return (1);
	local_index = -1;
	while (++local_index < size)
		result[local_index] = src[local_index];
	result[local_index] = '\0';
	bowl->copy = result;
	bowl->str = src;
	bowl->size = local_index;
	return (0);
}

void	emergency_exit(int index, t_stock_str *result)
{
	int	local_index;

	local_index = -1;
	index = -1;
	while (++local_index != index)
		if (result[local_index].copy != NULL)
			free(result[local_index].copy);
	free(result);
}
