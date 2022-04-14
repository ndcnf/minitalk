/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 12:38:29 by Nadia             #+#    #+#             */
/*   Updated: 2022/04/14 15:58:07 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int x = 0;

void	handle_sigusr1(int sig)
{
//	static int	x = 0;
	(void)sig;
	if(x == 0)
		ft_printf("handler ici, pid %d\n", getpid());
}

int		main(void)
{
	struct sigaction	sa;

	sa.sa_handler = &handle_sigusr1;
	sigaction(SIGUSR1, &sa, NULL);

	while(1)
		pause();
	return (0);
}
