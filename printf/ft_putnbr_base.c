/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:21:32 by rodralva          #+#    #+#             */
/*   Updated: 2024/02/09 14:44:32 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long n, char *base, int *ret)
{
	int		i;

	i = n % 16;
	if (n / 16 != 0)
		ft_putnbr_base(n / 16, base, ret);
	ft_putchar(base[i], ret);
}
