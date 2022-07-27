/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:19:06 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/27 15:03:31 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int	main(int argc, char **argv)
{
	t_bigbro	bigbro;
	int			error_ret;

	if (argc < 5 || argc > 6)
		return (0);
	if (init_bigbro_data(&bigbro, argv) == -1)
		return (0);
	error_ret = philosopher_thread_create(&bigbro);
	philosopher_thread_join(&bigbro, error_ret);
	clear_bigbro_data(&bigbro);
	return (0);
}
