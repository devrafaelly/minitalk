/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:32:30 by marvin            #+#    #+#             */
/*   Updated: 2025/09/15 18:32:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

# define ZERO SIGUSR1
# define ONE SIGUSR2

static void	send_signal(char c, int server_pid)
{
	int	bit;
	int	i;
	i = 0;
	while (i < 8)
	{
		bit = (c >> i) & 1;
		if (bit == 1)
			kill(server_pid, ONE);
		else
			kill(server_pid, ZERO);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*message;
	pid_t	server_pid;

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
	while (*message)
	{
		send_signal(*message, server_pid);
		message++;
	}
	send_signal(*message, server_pid);
	return (0);
}
