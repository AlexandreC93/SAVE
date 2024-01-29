/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <lcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:10:55 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/10/30 19:06:26 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirect_builtin(t_command *cmd, t_minishell *ministruct,
	int tmp_in, int tmp_out)
{
	if (ft_strcmp(cmd->argv[0], "echo") == 0)
		return (echo(cmd->argv));
	if (ft_strcmp(cmd->argv[0], "cd") == 0)
		return (cd(cmd->argv, ministruct));
	if (ft_strcmp(cmd->argv[0], "pwd") == 0)
		return (pwd());
	if (ft_strcmp(cmd->argv[0], "export") == 0)
		return (export(cmd->argv, ministruct->envars, ministruct));
	if (ft_strcmp(cmd->argv[0], "unset") == 0)
		return (unset(cmd->argv, ministruct->envars, ministruct));
	if (ft_strcmp(cmd->argv[0], "env") == 0)
		return (print_env(ministruct->envars));
	if (ft_strcmp(cmd->argv[0], "exit") == 0)
		ft_exit(cmd->argv, ministruct, tmp_in, tmp_out);
	return (0);
}

int	is_builtin(char *exe)
{
	if (ft_strcmp(exe, "echo") == 0)
		return (1);
	if (ft_strcmp(exe, "cd") == 0)
		return (1);
	if (ft_strcmp(exe, "pwd") == 0)
		return (1);
	if (ft_strcmp(exe, "export") == 0)
		return (1);
	if (ft_strcmp(exe, "unset") == 0)
		return (1);
	if (ft_strcmp(exe, "env") == 0)
		return (1);
	if (ft_strcmp(exe, "exit") == 0)
		return (1);
	return (0);
}
