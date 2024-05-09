/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:05:04 by rodralva          #+#    #+#             */
/*   Updated: 2024/05/09 20:25:19 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	send_singal(char *argv, int pid_serv);

void	send_pid(int pid_serv)
{
	int	pid_client;
	int	i;
	int	comp;

	i = 0;
	comp = 1 << 31;
	pid_client = getpid();
	while (i < 32)
	{
		if (pid_client & comp)
			kill(pid_serv, SIGUSR2);
		else
			kill(pid_serv, SIGUSR1);
		pid_client <<= 1;
		usleep(100);
		i++;
	}
	
}

void	handler(int signal)
{
	if (signal == SIGUSR2)
		send_singal(NULL, 0);
	else if (signal == SIGUSR1)
		exit(0);
}

void	send_singal(char *argv, int pid_serv)
{
	static char *str;
	static int	i;
	static int	j;
	static int	pid;
	char	c;

	if (argv)
		str = argv;
	if (pid_serv)
		pid = pid_serv;
	if (i < 8)
	{
		c = str[j];
		c <<= i;
		if (c & 10000000)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i++;
	}
	else if (i == 8)
	{
		j++;
		i = 0;
		send_singal(NULL, 0);
	}
}

int main(int argc, char **argv)
{
	int pid_serv;

	if (argc != 3)
		return (0);
	pid_serv = ft_atoi(argv[1]);
	send_pid(pid_serv);
	send_singal(argv[2], pid_serv);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();		
}
