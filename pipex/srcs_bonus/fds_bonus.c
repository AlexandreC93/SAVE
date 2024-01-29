/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fds_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <lcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:29:54 by lcadinot          #+#    #+#             */
/*   Updated: 2023/08/14 19:43:29 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

char	*find_path(char **envp)
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
		msg_err(ERR_ENVP);
	return (*envp + 5);
}

void	get_in(char **argv, t_ppxb *pipex)
{
	if (!ft_strncmp("here_doc", argv[1], 9))
		here_doc(argv[2], pipex);
	else
	{
		pipex->infile = open(argv[1], O_RDONLY);
		if (pipex->infile < 0)
			msg_err(ERR_INFILE);
	}
}

void	get_out(char *argv, t_ppxb *pipex)
{
	if (pipex->here_doc)
		pipex->outfile = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0000644);
	else
		pipex->outfile = open(argv, O_CREAT | O_RDWR | O_TRUNC, 0000644);
	if (pipex->outfile < 0)
	{
		close(pipex->infile);
		msg_err(ERR_OUTFILE);
	}
}
