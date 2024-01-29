/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 22:08:59 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/10/30 21:06:04 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_status = 0;

int	parse_commands(int argc, char **argv, t_minishell *mini_struct);

int	check_pipe(t_minishell *mini_struct, char *line)
{
	char		*token;
	int			i;

	i = 0;
	while (mini_struct->lines[i])
		i++;
	if (mini_struct->lines[0][0] == '|')
	{
		token = ft_substr(line, 0, 2);
		ft_free_2d_list(mini_struct->lines);
		print_error("syntax error near unexpected token", NULL, token, 2);
		return (free(token), 0);
	}
	else if (mini_struct->lines[i - 1][0] == '|')
	{
		token = ft_substr(mini_struct->lines[i - 1], 0, 2);
		ft_free_2d_list(mini_struct->lines);
		print_error("syntax error near unexpected token", NULL, token, 2);
		return (free(token), 0);
	}
	return (1);
}

void	real_free(t_minishell *mini_struct)
{
	rl_clear_history();
	free_envars(mini_struct->envars);
	free(mini_struct);
}

t_minishell	*ft_start(t_minishell *mini_struct, char **envp)
{
	mini_struct = init_all(envp);
	mini_struct->commands = NULL;
	return (mini_struct);
}

void	loop(char *line, t_minishell *mini_struct)
{
	if (line[0] == '\0' || line[0] == ' ' || line[0] == '\t')
		return ;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	add_history(line);
	mini_struct->lines = ft_split_argv(line);
	if (check_pipe(mini_struct, line) == 0)
		return ;
	if (fill_av(mini_struct) != ERROR)
		exec(mini_struct);
	ft_reset(mini_struct);
	free(line);
}

int	main(int argc, char **argv, char **envp)
{
	t_minishell	*mini_struct;
	char		*line;

	(void)argc;
	(void)argv;
	mini_struct = NULL;
	mini_struct = ft_start(mini_struct, envp);
	while (1)
	{
		init_sighandlers();
		line = readline(PROMPT);
		if (line == NULL)
			break ;
		if (check_quotes(line) == 0)
			continue ;
		loop(line, mini_struct);
	}
	return (real_free(mini_struct), 0);
}
