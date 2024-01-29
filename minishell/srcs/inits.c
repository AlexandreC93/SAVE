/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:58:32 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/10/30 21:06:58 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*init_command(t_minishell	*ministruct)
{
	t_command	*cmd;

	cmd = malloc(sizeof(t_command));
	if (!cmd)
		return (NULL);
	cmd->argv = NULL;
	cmd->envars = ministruct->envars;
	cmd->next = NULL;
	cmd->mini_struct = ministruct;
	return (cmd);
}

t_env	*init_env(char **envp)
{
	int		i;
	t_env	*envars;
	char	**split;

	i = 0;
	envars = NULL;
	while (envp[i])
	{
		split = ft_split(envp[i], '=');
		if (split[0] && split[1])
			envars = add_env(envars, split[0], split[1]);
		ft_free_2d_list(split);
		i++;
	}
	return (envars);
}

t_minishell	*reset_ministruct(t_minishell *mini_struct)
{
	mini_struct->lines = NULL;
	mini_struct->pipe_in = NULL;
	mini_struct->pipe_out = NULL;
	mini_struct->here_doc_lim = NULL;
	mini_struct->pids = NULL;
	mini_struct->append = 0;
	return (mini_struct);
}

t_minishell	*init_all(char **envp)
{
	t_minishell	*mini_struct;
	t_env		*envars;

	init_sighandlers();
	mini_struct = malloc(sizeof(t_minishell));
	if (!mini_struct)
		return (NULL);
	envars = init_env(envp);
	mini_struct->envars = envars;
	return (reset_ministruct(mini_struct));
}

void	ft_reset(t_minishell *mini_struct)
{
	free_mini_vars(mini_struct);
	reset_ministruct(mini_struct);
}
