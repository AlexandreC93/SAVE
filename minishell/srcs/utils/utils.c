/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:34:03 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/10/29 19:44:54 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// generate a prompt with the current directory bash style
// user@host:current_directory$
char	*get_mini_prompt(t_env *envars)
{
	char	*user;
	char	*host;
	char	*cwd;
	char	*prompt;
	char	*tmp;

	user = get_envar(envars, "USER");
	host = get_envar(envars, "HOSTNAME");
	if (!user)
		user = "user";
	if (!host)
		host = "host";
	cwd = getcwd(NULL, 0);
	prompt = ft_strjoin(user, "@");
	tmp = ft_strjoin(prompt, host);
	free(prompt);
	prompt = ft_strjoin(tmp, ":");
	free(tmp);
	tmp = ft_strjoin(prompt, cwd);
	free(prompt);
	free(cwd);
	prompt = ft_strjoin(tmp, "$ ");
	free(tmp);
	return (prompt);
}
