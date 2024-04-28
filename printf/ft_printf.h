/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:45:40 by rodralva          #+#    #+#             */
/*   Updated: 2024/02/09 14:09:59 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>

void	ft_putnbr(int n, int *ret);
void	ft_putnbr_base(unsigned long n, char *base, int *ret);
void	ft_putstr(char *s, int *ret);
void	ft_putchar(char c, int *ret);
void	ft_putnbr_unsigned(unsigned long n, int *ret);
int		ft_printf(char const *format, ...);

#endif
