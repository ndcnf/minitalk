/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 12:41:44 by nchennaf          #+#    #+#             */
/*   Updated: 2022/04/15 17:38:46 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "./Libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>

# define HELLO_S "Hi, I'm the server and here is my PID: %d\n"
# define HELLO_C "Hi server! Nice to meet you. I'm the client.\n"
# define PID_S "Your PID is %d, right?\n"
# define PID_C "Mine is %d.\n"
# define ERR_C "Hi, here's how to talk to me:\n"
# define HOW_TO "./client [Server PID] [Message]\n"
# define MSG "OK, I sent your message!\n"
# define BYE_S "Have a nice day!\n"
# define BYE_C "Have a wonderful day\n"
#endif
