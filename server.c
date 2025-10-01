/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaoliv <rafaoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:19:30 by marvin            #+#    #+#             */
/*   Updated: 2025/10/01 16:17:24 by rafaoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static void	decode_char(int signum, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static unsigned char	i;
	int						client_pid;
	int						sig;

	(void)context;
	client_pid = info->si_pid;
	if (signum == SIGUSR2)
		c |= (1 << i);
	i++;
	sig = SIGUSR1;
	if (i == 8)
	{
		if (c == '\0')
			ft_putchar_fd('\n', 1);
		else
			ft_putchar_fd(c, 1);
		i = 0;
		c = 0;
	}
	kill(client_pid, sig);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				server_pid;

	sa.sa_sigaction = decode_char;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	server_pid = getpid();
	ft_printf("server PID:%d\n", (int)server_pid);
	while (1)
		pause();
	return (0);
}
