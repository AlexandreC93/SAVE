/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <lcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:03:47 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/10/30 20:28:05 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_syntax(t_minishell *memo, int index, int letter)
{
	char		*line;
	char		*token;

	line = &memo->lines[index][letter + 1];
	if (get_chevron_nb(line) > 1)
	{
		token = ft_substr(line, 1, 2);
		print_error("syntax error near unexpected token", NULL, token, 2);
		return (free(token), 0);
	}
	if (!memo->lines[index + 1])
	{
		if (!line[0] || (ft_ischevron(line[0]) && !line[1]))
		{
			if (memo->pipe_in || memo->pipe_out || memo->here_doc_lim)
				print_error("syntax error near unexpected token", NULL,
					memo->lines[index - 1], 2);
			else
				print_error("syntax error near unexpected token", NULL,
					"newline", 2);
			return (0);
		}
	}
	return (1);
}

static int	check_here(t_minishell *memo, int index, int j)
{
	if (memo->lines[index][j] == '<')
	{
		memo->lines[index][j] = '\0';
		if (check_syntax(memo, index, j) == 0)
			return (-1);
		if (memo->lines[index][j + 1] == '<')
		{
			if (!memo->lines[index][j + 2])
				return (memo->here_doc_lim
					= ft_strdup(memo->lines[index + 1]), index + 2);
			else
				memo->here_doc_lim = ft_strdup(&memo->lines[index][j + 2]);
		}
		else
		{
			if (!memo->lines[index][j + 1])
				return (memo->pipe_in
					= ft_strdup(memo->lines[index + 1]), index + 2);
			else
				memo->pipe_in
					= ft_strdup(&memo->lines[index][j + 1]);
		}
		return (index + 1);
	}
	return (index);
}

static int	check_red(t_minishell *memo, int index, int j)
{
	if (memo->lines[index][j] == '>')
	{
		memo->lines[index][j] = '\0';
		if (check_syntax(memo, index, j) == 0)
			return (-1);
		if (memo->lines[index][j + 1] == '>')
		{
			memo->append = 1;
			if (!memo->lines[index][j + 2])
				return (memo->pipe_out
					= ft_strdup(memo->lines[index + 1]), index + 2);
			else
				memo->pipe_out = ft_strdup(&memo->lines[index][j + 2]);
		}
		else
		{
			if (!memo->lines[index][j + 1])
				return (memo->pipe_out
					= ft_strdup(memo->lines[index + 1]), index + 2);
			else
				memo->pipe_out = ft_strdup(&memo->lines[index][j + 1]);
		}
		return (index + 1);
	}
	return (index);
}

int	check_chev(t_minishell *memo, int *ret, int index, int j)
{
	if (memo->lines[index][j] == '<')
	{
		*ret = check_here(memo, index, j);
		if (*ret == -1)
			return (-1);
		if (index - *ret && j > 0)
			*ret -= 1;
		return (0);
	}
	else if (memo->lines[index][j] == '>')
	{
		*ret = check_red(memo, index, j);
		if (*ret == -1)
			return (-1);
		if (index - *ret && j > 0)
			*ret -= 1;
		return (0);
	}
	return (5);
}
