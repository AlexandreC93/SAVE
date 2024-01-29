/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:07:48 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/10/30 21:05:29 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_fd_in(t_minishell *mini_struct, int tmp_in)
{
	int	fd_in;

	if (mini_struct->pipe_in)
		fd_in = open(mini_struct->pipe_in, O_RDONLY);
	else if (mini_struct->here_doc_lim)
	{
		ft_here_doc(mini_struct->here_doc_lim);
		fd_in = open(HERE_DOC_PATH, O_RDONLY);
	}
	else
		fd_in = dup(tmp_in);
	return (fd_in);
}

int	set_fd_out(t_minishell *mini_struct, int tmp_out)
{
	int	fd_out;

	if (mini_struct->pipe_out && mini_struct->append)
		fd_out = open(mini_struct->pipe_out,
				O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (mini_struct->pipe_out)
		fd_out = open(mini_struct->pipe_out,
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd_out = dup(tmp_out);
	return (fd_out);
}

void	restore_fd(int tmp_in, int tmp_out, int *fd_in_out)
{
	(void)fd_in_out;
	dup2(tmp_in, STDIN_FILENO);
	dup2(tmp_out, STDOUT_FILENO);
	close(tmp_in);
	close(tmp_out);
}

int	set_pipes(t_command *tmp, int *fd_in, int *fd_out, int tmp_out)
{
	int	fd_pipe[2];

	dup2(*fd_in, STDIN_FILENO);
	close(*fd_in);
	if (!tmp->next)
	{
		*fd_out = set_fd_out(tmp->mini_struct, tmp_out);
		if (*fd_out == -1)
			return (0);
	}
	else
	{
		if (pipe(fd_pipe) == -1)
			return (dup2(*fd_out, STDOUT_FILENO), close(*fd_out), 0);
		*fd_out = fd_pipe[1];
		*fd_in = fd_pipe[0];
	}
	dup2(*fd_out, STDOUT_FILENO);
	close(*fd_out);
	return (1);
}
