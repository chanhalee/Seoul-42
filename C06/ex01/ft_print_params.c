/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chahale@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 03:25:44 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/23 03:30:45 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = argc;
	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
			write(1, (argv[i] + j), 1);
		write(1, "\n", 1);
	}
	return (0);
}
