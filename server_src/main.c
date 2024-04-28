/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:57:31 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/26 16:46:24 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	controlador(int signal)
{
	static char	c;
	static char	*str;
	static int	i;


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
			free(str);
			str = NULL;
		}
		c = c & 0;
		i = 0;
	}	
}

int	main(void)
{
	ft_printf("%d\n",getpid());
	signal(SIGUSR1, controlador);
	signal(SIGUSR2, controlador);
	while(1)
		pause();
	return(0);
}

