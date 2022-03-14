/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:46:41 by chanhale          #+#    #+#             */
/*   Updated: 2022/03/08 23:58:58 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_bonus.h"

t_client_data	g_infobox;

static void	send_char(void)
{
	if (g_infobox.msg[g_infobox.index])
	{
		if (g_infobox.msg[g_infobox.index] >> g_infobox.bit & 1)
			kill(g_infobox.server_pid, SIGUSR2);
		else
			kill(g_infobox.server_pid, SIGUSR1);
	}
	else if (g_infobox.bit >= 0)
		kill(g_infobox.server_pid, SIGUSR1);
}

static void	client_handler(int signal)
{
	if ((((g_infobox.msg[g_infobox.index] >> g_infobox.bit)
				& 1) + SIGUSR1) == signal)
	{
		g_infobox.bit--;
		if (g_infobox.bit < 0 && g_infobox.msg[g_infobox.index])
		{
			g_infobox.bit = 7;
			g_infobox.index++;
		}
	}
	usleep(10);
	send_char();
}

static void	client_initiate(char **argv)
{
	static struct sigaction	sig_act;

	g_infobox.server_pid = ft_atoi_custom(argv[1]);
	if (g_infobox.server_pid == TYPE_PARSE_ERROR)
		exit(1);
	g_infobox.bit = 7;
	g_infobox.index = 0;
	g_infobox.msg = argv[2];
	sigemptyset(&(sig_act.sa_mask));
	sigaddset(&(sig_act.sa_mask), SIGUSR1);
	sigaddset(&(sig_act.sa_mask), SIGUSR2);
	sig_act.sa_handler = &client_handler;
	sigaction(SIGUSR1, &sig_act, NULL);
	sigaction(SIGUSR2, &sig_act, NULL);
}

int	main(int argc, char **argv)
{
	int					retry;
	int					time_out;

	if (argc != 3)
		return (0);
	client_initiate(argv);
	retry = 10;
	send_char();
	while (retry)
	{
		time_out = usleep(30000);
		if (time_out == 0 && (--retry) < 0)
		{
			if (g_infobox.msg[g_infobox.index] && g_infobox.bit >= 0)
				send_char();
			else
				break ;
		}
	}
	return (0);
}
