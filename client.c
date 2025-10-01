/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaoliv <rafaoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:32:30 by marvin            #+#    #+#             */
/*   Updated: 2025/10/01 16:18:22 by rafaoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

volatile sig_atomic_t	g_timeout = 1;

static void	signal_control(int signum)
{
	if (signum == SIGUSR1)
		g_timeout = 0;
}

static void	send_signal(char c, int server_pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_timeout = 1;
		if ((c >> i) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		while (g_timeout)
			pause();
		i++;
	}
}

static void	encode_char(char *s, int server_pid)
{
	while (*s)
	{
		send_signal(*s, server_pid);
		s++;
	}
	send_signal(*s, server_pid);
}

int	main(int argc, char **argv)
{
	char				*message;
	pid_t				server_pid;
	struct sigaction	sa;

	sa.sa_handler = signal_control;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	if (argc != 3)
	{
		ft_putendl_fd("Uso: ./client <PID> <mensagem>", 2);
		return (1);
	}
	server_pid = (pid_t)ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_putendl_fd("Erro: PID inválido.", 2);
		return (1);
	}
	message = argv[2];
	encode_char(message, server_pid);
	return (0);
}
