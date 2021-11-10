/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chahale@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 03:31:39 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/23 03:35:38 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = argc;
	i = 0;
	while (--argc > 0)
	{
		j = -1;
		while (argv[argc][++j])
			write(1, (argv[argc] + j), 1);
		write(1, "\n", 1);
	}
	return (0);
}
