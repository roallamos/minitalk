/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:19:05 by rodralva          #+#    #+#             */
/*   Updated: 2024/02/09 12:46:41 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *ret)
{
	if (!s)
	{
		write(1, "(null)", 6);
		*ret += 6;
	}
	else
	{
		while (*s)
		{
			ft_putchar(*s, ret);
			s++;
		}
	}
}
