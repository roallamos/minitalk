/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:32:02 by rodralva          #+#    #+#             */
/*   Updated: 2024/05/13 19:53:53 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include "../printf/ft_printf.h"
# include "../libft/libft.h"

void	send_singal(char *argv, int pid_serv);

#endif
