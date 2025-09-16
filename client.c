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

# define BIT_ZERO SIGUSR1
# define BIT_ONE SIGUSR2

static void	send_signal(char c, int server_pid)
{
	int	bit;
	int	i;
	i = 0;
	while (i < 8)
	{
		bit = (c >> i) & 1;
		if (bit == 1)
			kill(server_pid, BIT_ONE);
		else
			kill(server_pid, BIT_ZERO);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*message;
	pid_t	server_pid;

	if (argc != 3)
	{
		ft_printf("Informar PID do server e mensagem\n");
		return (1);
	}
	server_pid = (pid_t)ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_printf("Erro: PID inválido\n");
		return (1);
	}
	message = argv[2];
	while (*message)
	`{
		send_signal(*message, server_pid);
		message++;
	}
	send_signal(*message, server_pid);
	return (0);
}
