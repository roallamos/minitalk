/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:10:54 by rodralva          #+#    #+#             */
/*   Updated: 2024/05/14 15:11:02 by rodralva         ###   ########.fr       */
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

void	translate_signal(int *i, int signal, char *c)
{
	if (signal == SIGUSR2)
		*c = *c | 1;
	*i += 1;
	if (*i != 8)
		*c <<= 1;
}

void	get_char(int signal, int *pid, int *j)
{
	static char	c;
	static char	*str;
	static int	i;

	translate_signal(&i, signal, &c);
	if (i == 8)
	{
		str = ft_strjoin_free(str, &c);
		if (!c)
		{
			ft_printf("%s\n", str);
			kill(*pid, SIGUSR1);
			*j = 0;
			*pid = 0;
			free(str);
			str = NULL;
		}
		c = c & 0;
		i = 0;
	}
	if (*pid != 0)
		kill(*pid, SIGUSR2);
}

void	handler(int signal)
{
	static int	j;
	static int	pid;

	if (j < 32)
		get_client_pid(&j, &pid, signal);
	else
		get_char(signal, &pid, &j);
}
