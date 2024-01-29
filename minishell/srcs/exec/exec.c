/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:35:15 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/10/30 17:30:06 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_cmds_qqty(t_minishell *mini_struct)
{
	int			cmds_qqty;
	t_command	*tmp;

	cmds_qqty = 0;
	tmp = mini_struct->commands;
	while (tmp)
	{
		cmds_qqty++;
		tmp = tmp->next;
	}
	return (cmds_qqty);
}

void	fill_pid(t_minishell *mini_struct, int pid)
{
	int	*ptr;

	ptr = (int *)malloc(sizeof(int));
	*ptr = pid;
	ft_lstadd_back(&mini_struct->pids, ft_lstnew(ptr));
}

int	do_exec(t_command *tmp, int fd_in, int fd_out)
{
	int	pid;
	int	ret_val;

	pid = fork();
	errno = 0;
	if (pid == -1)
		return (print_error_errno(tmp->argv[0], NULL), 1);
	else if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		close(fd_in);
		close(fd_out);
		ret_val = ft_execvp(tmp, fd_in, fd_out);
		if (ret_val == 127 || ret_val == 2)
			print_error(tmp->argv[0], "command not found", NULL, ret_val);
		else if (errno != 0 && ret_val != 0)
			print_error_errno(tmp->argv[0], NULL);
		free_all(tmp->mini_struct);
		exit(g_status);
	}
	else
		return (fill_pid(tmp->mini_struct, pid), g_status);
}

int	exec(t_minishell *mini_struct)
{
	int			tmp_in;
	int			tmp_out;
	int			fd_in_out[2];
	t_command	*tmp;

	g_status = 0;
	tmp_in = dup(STDIN_FILENO);
	tmp_out = dup(STDOUT_FILENO);
	fd_in_out[0] = set_fd_in(mini_struct, tmp_in);
	if (fd_in_out[0] == -1)
		return (print_error_errno(mini_struct->commands->argv[0], NULL), 1);
	tmp = mini_struct->commands;
	while (tmp)
	{
		if (set_pipes(tmp, &fd_in_out[0], &fd_in_out[1], tmp_out))
		{
			if (is_builtin(tmp->argv[0]) && get_cmds_qqty(mini_struct) == 1)
				redirect_builtin(tmp, mini_struct, tmp_in, tmp_out);
			else
				g_status = do_exec(tmp, tmp_in, tmp_out);
		}
		tmp = tmp->next;
	}
	restore_fd(tmp_in, tmp_out, fd_in_out);
	return (g_status = wait_last_cmd(mini_struct->pids), 1);
}
