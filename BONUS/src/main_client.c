/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:54:41 by carolina          #+#    #+#             */
/*   Updated: 2023/05/11 17:38:46 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	g_ready;

/*Intercepts signals sent by the server.
SIGUSR1 = ready to receive next bit.
SIGUSR2 = All message has been received*/
void	signal_server_handler(int signal_server, \
siginfo_t *info, void *ucontext)
{
	(void)signal_server;
	(void)info;
	(void)ucontext;
	g_ready = 0;
}

/*Sends each bit (from right to left) of each letter using signals
 so that the server's program can intercept them*/
void	char_to_bit(char c, int pid)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		g_ready = 1;
		if (c & (1 << bit))
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		bit--;
		while (g_ready == 1)
		{
		}
	}
}

/*Checks the validity of the arguments:
- Exactly 3 arguments
- 3ed argument has to be a non negative number*/
void	args_check(int argc, char **argv)
{
	int	i;

	if (argc != 3)
	{
		ft_printf("Error :\nNumber of arguments\n");
		exit(1);
	}
	i = 0;
	while (argv[1][i] != '\0')
	{
		if (ft_isdigit(argv[1][i]) == false)
		{
			ft_printf("Error :\nWrong PID\n");
			exit(1);
		}
		i++;
	}
}

/*Sends message letter by letter to the char_to_bit function*/
int	main(int argc, char **argv)
{
	int					pid;
	int					i;
	struct sigaction	signal_server;

	sigemptyset(&signal_server.sa_mask);
	signal_server.sa_flags = SA_SIGINFO;
	signal_server.sa_sigaction = &signal_server_handler;
	if (sigaction(SIGUSR1, &signal_server, NULL) == -1)
		return (EXIT_FAILURE);
	args_check(argc, argv);
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
		char_to_bit(argv[2][i++], pid);
	char_to_bit('\0', pid);
	return (EXIT_SUCCESS);
}
