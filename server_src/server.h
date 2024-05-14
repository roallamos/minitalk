/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:58:35 by rodralva          #+#    #+#             */
/*   Updated: 2024/05/14 15:14:40 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include "../printf/ft_printf.h"
# include "../libft/libft.h"
# include "server.h"

void	get_client_pid(int *j, int *pid, int signal);
void	terminate_client(char *str, int *pid, int *j);
void	translate_signal(int *i, int signal, char *c);
void	get_char(int signal, int *pid, int *j);
void	handler(int signal);

#endif
