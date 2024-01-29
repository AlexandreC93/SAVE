/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <lcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:48:10 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/10/30 14:02:31 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_handler(int sig)
{
	(void)sig;
	g_status = 130;
	ft_putstr("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	init_sighandlers(void)
{
	struct sigaction	sigint;
	struct sigaction	sigquit;

	sigint = (struct sigaction){0};
	sigquit = (struct sigaction){0};
	sigint.sa_handler = sigint_handler;
	sigint.sa_flags = 0;
	sigaction(SIGINT, &sigint, NULL);
	sigquit.sa_handler = SIG_IGN;
	sigquit.sa_flags = 0;
	sigaction(SIGQUIT, &sigquit, NULL);
}
