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

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc != 3)
		kill ; // seria isso? verificar
	// tranformar PID em numero
	server_pid = (pid_t)ft_atoi(argv[1]);
	// verificar se PID é valido
	if (server_pid <= 0)
	{
		ft_printf("Erro: PID inválido\n");
		return (1);
	}
	// transforma caracteres em bits
	argv[2];
	// envia para server
	while ()
	{
		kill(pid_t pid, int sig);
	}
}