/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:03:47 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/10/30 16:42:10 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_token(t_minishell *memo, int index)
{
	size_t	j;
	int		ret;
	int		check;

	j = 0;
	if (memo->lines[index][0] == '\'' || memo->lines[index][0] == '\"')
		return (index);
	while (memo->lines[index][j])
	{
		check = check_chev(memo, &ret, index, j);
		if (check == 0)
			return (ret);
		else if (check == -1)
			return (-1);
		j++;
	}
	return (index);
}

static int	fill_argvs(t_minishell *ministruct,
	t_command *current_cmd, int i, int j)
{
	int	k;

	k = 0;
	while (j > 0 && ministruct->lines[i])
	{
		i = check_token(ministruct, i);
		if (i == ERROR)
			return (ERROR);
		if (!ministruct->lines[i] || ministruct->lines[i][0] == '|')
			break ;
		current_cmd->argv[k] = ft_expand
			(ministruct->lines[i], ministruct->envars);
		k++;
		j--;
		i++;
	}
	return (0);
}

static int	get_argv_len(char	**lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (lines[i][0] == '|')
			return (i);
		i++;
	}
	return (i);
}

static t_command	*update_cmd(t_minishell *ministruct,
		t_command *last_cmd, t_command *current_cmd)
{
	if (!last_cmd)
		ministruct->commands = current_cmd;
	else
		last_cmd->next = current_cmd;
	return (current_cmd);
}

int	fill_av(t_minishell *memo)
{
	int			i;
	int			j;
	t_command	*last_cmd;
	t_command	*current_cmd;

	i = 0;
	last_cmd = NULL;
	while (memo->lines[i])
	{
		if (memo->lines[i][0] == '|')
		{
			i++;
			continue ;
		}
		j = get_argv_len(memo->lines + i);
		current_cmd = init_command(memo);
		current_cmd->argv = ft_calloc(j + 1, sizeof(char *));
		if (fill_argvs(memo, current_cmd, i, j) == ERROR)
			return (ERROR);
		last_cmd = update_cmd(memo, last_cmd, current_cmd);
		if (!memo->lines[i + 1])
			break ;
		i += j;
	}
	return (1);
}
