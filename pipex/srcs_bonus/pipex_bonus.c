/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <lcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:29:39 by lcadinot          #+#    #+#             */
/*   Updated: 2023/08/14 18:37:06 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	creat_pipes(t_ppxb *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_nmbs - 1)
	{
		if (pipe(pipex->pipe + 2 * i) < 0)
			parent_free(pipex);
		i++;
	}
}

void	close_pipes(t_ppxb *pipex)
{
	int	i;

	i = 0;
	while (i < (pipex->pipe_nmbs))
	{
		close(pipex->pipe[i]);
		i++;
	}
}

static void	ft_init(t_ppxb *pipex, char **argv, int argc)
{
	get_in(argv, pipex);
	get_out(argv[argc - 1], pipex);
	pipex->cmd_nmbs = argc - 3 - pipex->here_doc;
	pipex->pipe_nmbs = 2 * (pipex->cmd_nmbs - 1);
	pipex->pipe = (int *)malloc(sizeof(int) * pipex->pipe_nmbs);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_ppxb	pipex;
	int		i;

	i = 0;
	if (argc < args_in(argv[1], &pipex))
		return (msg(ERR_INPUT));
	ft_init(&pipex, argv, argc);
	if (!pipex.pipe)
		msg_err(ERR_PIPE);
	pipex.env_path = find_path(envp);
	pipex.cmd_paths = ft_split(pipex.env_path, ':');
	if (!pipex.cmd_paths)
		pipe_free(&pipex);
	creat_pipes(&pipex);
	pipex.idx = -1;
	while (++(pipex.idx) < pipex.cmd_nmbs)
		child(pipex, argv, envp);
	close_pipes(&pipex);
	while (i < wait(NULL))
		;
	return (parent_free(&pipex), 0);
}
