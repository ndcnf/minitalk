/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 12:38:29 by Nadia             #+#    #+#             */
/*   Updated: 2022/04/16 01:32:28 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/********************************************
*	Convert a binary into char				*
*	Use of a truth table to handle the msg	*
********************************************/
void	handle_sig(int sig)
{
	static char	bits = 0;
	static int	i = 8;

	bits = bits << 1;
	if (sig == SIGUSR1)
		bits = bits | 1;
	i--;
	if (i == 0)
	{
		ft_putchar_fd(bits, 1);
		i = 8;
	}
}

int	main(void)
{
	signal(SIGUSR1, handle_sig);
	signal(SIGUSR2, handle_sig);
	ft_printf(HELLO_S, getpid());
	while (1)
		pause();
	return (0);
}
