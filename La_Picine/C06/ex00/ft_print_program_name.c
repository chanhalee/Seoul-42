/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chahale@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 03:12:53 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/23 04:15:12 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	index;

	index = argc;
	index = -1;
	while (argv[0][++index])
		write(1, (argv[0] + index), 1);
	write(1, "\n", 1);
	return (0);
}
