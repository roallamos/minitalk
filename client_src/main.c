/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:29:52 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/26 16:34:03 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	char c;

	i = 0;
	j = 0;
	if (argc != 3)
		return (0);
	while(argv[2][i])
	{
		c = argv[2][i];
		while(j < 8)
		{
			if (c & 10000000)
				kill(ft_atoi(argv[1]), SIGUSR2);
			else
				kill(ft_atoi(argv[1]), SIGUSR1);
			j++;
			c = c << 1;
			usleep(100);
		}
		j = 0;
		i++;
	}
	c = 0;
	while(j < 8)
	{
		if (c & 10000000)
			kill(ft_atoi(argv[1]), SIGUSR2);
		else
			kill(ft_atoi(argv[1]), SIGUSR1);
		j++;
		c = c << 1;
		usleep(10);
	}
	return (0);
}
