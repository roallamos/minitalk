/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:35:44 by rodralva          #+#    #+#             */
/*   Updated: 2024/02/08 16:34:56 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *ret)
{
	char	chr;
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-', ret);
	}
	chr = nb % 10 + '0';
	if (nb / 10 != 0)
		ft_putnbr(nb / 10, ret);
	ft_putchar(chr, ret);
}
