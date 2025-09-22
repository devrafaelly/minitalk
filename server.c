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

# define ZERO SIGUSR1
# define ONE SIGUSR2

static unsigned char	c;

static void	handler(int signum)
{
	static int	i;

	if (signum == ONE)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		write (1, &c, 1);
		if (c == '\0')
			write (1, "\n", 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t			server_pid;

	server_pid = getpid();
	ft_printf("server PID:%d\n", (int)server_pid);
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(ZERO, &sa, NULL);
	sigaction(ONE, &sa, NULL);
	while (1)
		pause();
	return (0);
}
