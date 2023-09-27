/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:50:03 by carolina          #+#    #+#             */
/*   Updated: 2023/05/11 15:35:27 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define _XOPEN_SOURCE 700

# include "../ft_printf/ft_printf.h"

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <signal.h>
# include <sys/wait.h>

/*MAIN CLIENT*/
void	char_to_bit(char c, int pid);
void	args_check(int argc, char **argv);
void	signal_server_handler(int signal_server, \
siginfo_t *info, void *ucontext);

/*MAIN SERVEUR*/
void	signal_client_handler(int signal_client, \
siginfo_t *info, void *ucontext);
void	bit_to_char(int n, pid_t pid_client);
int		from_bit_to_ascii(int *char_in_bit);
void	bit_to_char2(int *char_in_bit, pid_t pid_client);

/*UTILS*/
int		ft_atoi(char *nptr);
bool	ft_isdigit(int c);
int		ft_strlen(char *str);
char	*ft_joinstr_minitalk(char *s1, char s2);

/*UTILS2*/
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
