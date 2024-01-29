/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 21:40:36 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/10/30 16:49:14 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_t_env(t_env *envar)
{
	free(envar->key);
	free(envar->value);
	free(envar);
}

void	free_t_commands(t_command *cmd)
{
	t_command	*tmp;

	while (cmd)
	{
		tmp = cmd;
		cmd = cmd->next;
		ft_free_2d_list(tmp->argv);
		free(tmp);
	}
}

void	free_envars(t_env *envars)
{
	t_env	*tmp;

	while (envars)
	{
		tmp = envars;
		envars = envars->next;
		free_t_env(tmp);
	}
}

void	free_mini_vars(t_minishell *mini_struct)
{
	if (mini_struct->lines)
		ft_free_2d_list(mini_struct->lines);
	if (mini_struct->pipe_in)
		free(mini_struct->pipe_in);
	if (mini_struct->pipe_out)
		free(mini_struct->pipe_out);
	if (mini_struct->here_doc_lim)
		free(mini_struct->here_doc_lim);
	if (mini_struct->pids)
		ft_lstclear(&mini_struct->pids, free);
	if (mini_struct->commands)
		free_t_commands(mini_struct->commands);
}
