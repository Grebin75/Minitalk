/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:08:22 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/06/08 19:24:59 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static void	putnb(int x)
{
	if (x > 9)
		putnb((x / 10));
	write(1, &"0123456789"[x % 10], 1);
}

void	sighandle(int signal)
{
	static char		binary[8] = {128, 64, 32, 16, 8, 4, 2, 1};
	static int		i;
	static char		bit;

	if (signal == SIGUSR1)
		i++;
	if (signal == SIGUSR2)
		bit = bit + binary[i++];
	if (i == 8)
	{
		if (bit)
			write (1, &bit, 1);
		else
			write(1, "\n", 1);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)**argv;	
	if (argc != 1)
		return (write(2, "\033[1;34mTry again with ./server\n\033[0m", 36));
	pid = getpid();
	write (1, "\033[1;34mSERVER PID: \033[1;37m", 27);
	putnb(pid);
	write (1, "\033[1;34m.\n\033[0;37m", 17);
	signal(SIGUSR1, sighandle);
	signal(SIGUSR2, sighandle);
	while (1)
		pause ();
}
