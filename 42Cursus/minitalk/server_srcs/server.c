/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:47:27 by chanhale          #+#    #+#             */
/*   Updated: 2022/03/08 23:58:07 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

t_infobox	g_infobox;

static void	server_initiate(void)
{
	ft_printf("pid: %d\n", getpid());
	g_infobox.character = 0;
	g_infobox.client_id = 0;
	g_infobox.counter = 0;
}

static void	info_clear(pid_t client_id)
{
	g_infobox.character = 0;
	g_infobox.client_id = client_id;
	g_infobox.counter = 0;
}

static void handler(int signal, siginfo_t *info, void *func)
{
	(void)func;
	if(g_infobox.client_id != info->si_pid)
		info_clear(info->si_pid);
	if(signal == SIGUSR1)
		g_infobox.character = (g_infobox.character << 1) | 0;
	else
		g_infobox.character = (g_infobox.character << 1) | 1;
	g_infobox.counter++;
	if (g_infobox.counter == 8)
	{
		ft_putchar_fd(g_infobox.character, 1);
		info_clear(info->si_pid);
	}
	kill(info->si_pid, signal);
}

int	main(void)
{
	struct sigaction	sig_act;

	server_initiate();
	sig_act.sa_flags = SA_SIGINFO;
	sigemptyset(&sig_act.sa_mask);
	sigaddset(&sig_act.sa_mask, SIGUSR1);
	sigaddset(&sig_act.sa_mask, SIGUSR2);
	sig_act.sa_sigaction = &handler;
	sigaction(SIGUSR1, &sig_act, NULL);
	sigaction(SIGUSR2, &sig_act, NULL);
	while(1)
		sleep(1);
}
