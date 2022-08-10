/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:08:18 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/06/08 19:32:40 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static int	converter(int server_pid, char *msg)
{
	int	bit;
	int	i;

	i = -1;
	while (msg[++i])
	{
		bit = 7;
		while (bit > -1)
		{
			kill(server_pid, SIGUSR1 + 2 * (msg[i] >> bit & 1));
			usleep(100);
			bit--;
		}
	}
	bit = 7;
	while (bit-- > -1)
	{
		kill(server_pid, SIGUSR1);
		usleep(100);
	}
	return (0);
}

static int	digit(char *x)
{
	int	i;

	i = -1;
	while (x[++i])
		if (x[i] < '0' || x[i] > '9')
			return (0);
	return (1);
}

static int	ft_atoi(char *x)
{
	int	resultado;
	int	i;

	i = 0;
	resultado = 0;
	while (x[i] >= '0' && x[i] <= '9')
		resultado = resultado * 10 + ((x[i++] - 48));
	return (resultado);
}

int	main(int argc, char **argv)
{
	int	server_pid;
	int	i;

	(void)i;
	if (argc != 3)
	{
		write(STDERR_FILENO, "Try ./client [Server Pid] [Your Message].\n", 43);
		return (0);
	}
	if (digit(argv[1]) == 1)
		server_pid = ft_atoi(argv[1]);
	else
		return (write(STDERR_FILENO, "\033[0;33mInvalid PID.\n\033[1", 14));
	converter(server_pid, argv[2]);
}
