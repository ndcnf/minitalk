/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 12:38:18 by Nadia             #+#    #+#             */
/*   Updated: 2022/04/16 01:33:05 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/********************************************
*	Convert a char into binary				*
*	Ex: 'a' = 97 = 01100001					*
*	Use of a truth table to handle the msg	*
********************************************/
void	babelfish(char c, pid_t pid)
{
	int	i;

	i = 8;
	while (i)
	{
		i--;
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
	}
}

void	send_msg(pid_t pid, char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		babelfish(message[i], pid);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	srv_pid;
	char	*message;

	if (argc < 3)
	{
		ft_putstr_fd(ERR_C HOW_TO BYE_C, 1);
		return (EXIT_FAILURE);
	}
	srv_pid = ft_atoi(argv[1]);
	ft_printf(HELLO_C PID_S, srv_pid);
	ft_printf(PID_C, getpid());
	message = argv[2];
	send_msg(srv_pid, message);
	ft_putstr_fd(MSG, 1);
	return (EXIT_SUCCESS);
}
