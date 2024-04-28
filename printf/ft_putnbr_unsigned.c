/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:08:40 by rodralva          #+#    #+#             */
/*   Updated: 2024/02/09 14:09:29 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned long n, int *ret)
{
	char	chr;

	chr = n % 10 + '0';
	if (n / 10 != 0)
		ft_putnbr_unsigned(n / 10, ret);
	ft_putchar(chr, ret);
}
