/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:57:31 by rodralva          #+#    #+#             */
/*   Updated: 2024/05/13 21:46:05 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	get_client_pid(int *j, int *pid, int signal)
{
	if (signal == SIGUSR2)
		*pid = *pid | 1;
	*j += 1;
	if (*j != 32)
		*pid <<= 1;
}

void	terminate_client(char *str, int *pid, int *j)
{
	ft_printf("%s\n", str);
	kill(*pid, SIGUSR1);
	*j = 0;
	*pid = 0;
	free(str);
	str = NULL;
}

void	handler(int signal)
{
	static char	c;
	static char	*str;
	static int	i;
	static int	j;
	static int	pid;

	if (j < 32)
		get_client_pid(&j, &pid, signal);
	else
	{
		if (signal == SIGUSR2)
			c = c | 1;
		i++;
		if (i != 8)
			c = c << 1;
		else if (i == 8)
		{
			str = ft_strjoin_free(str, &c);
			if (!c)
			{
				ft_printf("%s\n", str);
				kill(pid, SIGUSR1);
				j = 0;
				pid = 0;
				free(str);
				str = NULL;
			}
			c = c & 0;
			i = 0;
		}
		if (pid != 0)
			kill(pid, SIGUSR2);
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGTERM);
	sa.sa_flags = 0;
	ft_printf("%d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
