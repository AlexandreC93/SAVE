/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <lcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:29:26 by lcadinot          #+#    #+#             */
/*   Updated: 2023/08/14 19:30:16 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	close_pipes(t_pipex *pipex)
{
	close(pipex->tube[0]);
	close(pipex->tube[1]);
}

char	*find_path(char **envp, t_pipex *pipex)
{
	char	**tmp;

	tmp = envp;
	while (*tmp && ft_strncmp("PATH", *envp, 4) != 0)
	{
		envp++;
		tmp++;
	}
	if (*tmp == NULL)
		envp = NULL;
	if (!envp)
	{
		close(pipex->infile);
		close(pipex->outfile);
		close_pipes(pipex);
		msg_err(ERR_ENVP);
	}
	return (*envp + 5);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;

	if (argc != 5)
		return (msg(ERR_INPUT));
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		msg_err(ERR_INFILE);
	pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipex.outfile < 0)
		return (close(pipex.infile), msg_err(ERR_OUTFILE), 1);
	if (pipe(pipex.tube) < 0)
		return (close(pipex.infile), close(pipex.outfile),
			msg_err(ERR_PIPE), 1);
	pipex.paths = find_path(envp, &pipex);
	pipex.cmd_paths = ft_split(pipex.paths, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		first_child(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		second_child(pipex, argv, envp);
	close_pipes(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	return (parent_free(&pipex), 0);
}
