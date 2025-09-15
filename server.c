/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:19:30 by marvin            #+#    #+#             */
/*   Updated: 2025/09/15 19:19:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include "libft.h"

// deve ser executado primeiro e deve printar o PID no terminal
int	main(void)
{
	pid_t	server_pid;
	server_pid = getpid();
	ft_printf("server PID:%d\n", (int)server_pid);
	// pega sinal do client
	sigaction();
}