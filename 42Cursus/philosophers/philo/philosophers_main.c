/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:19:06 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/24 22:21:57 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"
#include "./do_not_submit/do_not_submit.h"

int	main(int argc, char **argv)
{
	t_bigbro	*bigbro;

	if (argc < 5 || argc > 6)
		return (0);
	bigbro = init_bigbro_data(bigbro, argv);
	if(init_bigbro_data(bigbro, argv) == -1)
		return (0);
	printf("1\n");
	print_bigbro(&bigbro);
	clear_bigbro_data(&bigbro);
	system("leaks philosophers");
}
