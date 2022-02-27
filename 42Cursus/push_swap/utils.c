/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:03:31 by chanhale          #+#    #+#             */
/*   Updated: 2022/02/27 20:16:09 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	emergency_exit()
{
	write(2, "Error\n", 6);
	exit(1);
}

int	check_input(int argc, char **argv)
{

}