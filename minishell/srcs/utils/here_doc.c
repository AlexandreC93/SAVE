/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:53:02 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/10/30 11:06:07 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_here_doc(char *limiter)
{
	int		here_doc;
	char	*line;
	char	tmp_in;

	tmp_in = dup(STDIN_FILENO);
	here_doc = open(HERE_DOC_PATH, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (here_doc == -1)
		return (0);
	while (1)
	{
		line = readline("> ");
		if (!line || ft_strcmp(line, limiter) == 0)
		{
			close(STDIN_FILENO);
			dup2(tmp_in, STDIN_FILENO);
			break ;
		}
		ft_putstr_fd(line, here_doc);
		ft_putstr_fd("\n", here_doc);
		free(line);
	}
	free(line);
	close(here_doc);
	return (1);
}
