/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:13:09 by carolina          #+#    #+#             */
/*   Updated: 2023/05/11 17:40:58 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

/*Intercepts signals sent by the client.*/
void	signal_client_handler(int signal_client, \
siginfo_t *info, void *ucontext)
{
	pid_t	pid_client;

	(void)ucontext;
	pid_client = info->si_pid;
	if (signal_client == SIGUSR1)
		bit_to_char(1, pid_client);
	else if (signal_client == SIGUSR2)
		bit_to_char(0, pid_client);
}

/*Transforms from binary to ascii*/
int	from_bit_to_ascii(int *char_in_bit)
{	
	int	bit;
	int	sum;
	int	*binaire;

	binaire = malloc(sizeof(int) * 8);
	binaire[0] = 128;
	binaire[1] = 64;
	binaire[2] = 32;
	binaire[3] = 16;
	binaire[4] = 8;
	binaire[5] = 4;
	binaire[6] = 2;
	binaire[7] = 1;
	bit = 0;
	sum = 0;
	while (bit < 8)
	{
		sum = sum + (char_in_bit[bit] * binaire[bit]);
		bit++;
	}
	free(binaire);
	return (sum);
}

/*Transforms from binary to ascii to reform the message*/
void	bit_to_char(int n, pid_t pid_client)
{
	static int	bit = 0;
	static int	*char_in_bit;

	if (bit == 0)
		char_in_bit = ft_calloc(8, sizeof(int));
	if (bit < 8)
	{
		if (n == 1)
			char_in_bit[bit] = 1;
		bit++;
	}
	if (bit == 8)
	{
		bit_to_char2(char_in_bit, pid_client);
		bit = 0;
		free(char_in_bit);
	}
	if (kill(pid_client, SIGUSR1) == -1)
		exit(1);
}

void	bit_to_char2(int *char_in_bit, pid_t pid_client)
{
	static char	*str = NULL;

	str = ft_joinstr_minitalk(str, (char)from_bit_to_ascii(char_in_bit));
	if (from_bit_to_ascii(char_in_bit) == 0)
	{
		ft_printf("%s\n", str);
		if (kill(pid_client, SIGUSR2) == -1)
			exit(1);
		free(str);
		str = NULL;
	}
}

int	main(void)
{
	struct sigaction	signal_client;

	sigemptyset(&signal_client.sa_mask);
	signal_client.sa_flags = SA_SIGINFO;
	signal_client.sa_sigaction = &signal_client_handler;
	if (sigaction(SIGUSR1, &signal_client, NULL) == -1 || \
	sigaction(SIGUSR2, &signal_client, NULL) == -1)
		return (EXIT_FAILURE);
	ft_printf("PID : %d\n", getpid());
	while (1)
		continue ;
	return (EXIT_SUCCESS);
}
