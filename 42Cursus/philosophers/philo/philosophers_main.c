/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:19:06 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/24 17:30:33 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int	main(int argc, char **argv)
{
	t_bigbro	big_bro;

	if (argc < 5 || argc > 6)
		return (0);
	if(init_system(&big_bro, argv) == -1)
		return (0);
	
}