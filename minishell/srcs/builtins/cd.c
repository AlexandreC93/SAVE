/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <lcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:17:20 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/10/30 19:13:03 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd(char **args, t_minishell *ministruct)
{
	char	*path;
	char	*oldpwd;

	if (args[1] == NULL)
	{
		path = get_envar(ministruct->envars, "HOME");
		if (path == NULL)
			return (print_error("cd", NULL, "HOME not set", 1), 0);
	}
	else if ((ft_strlen(args[1]) == 1) && args[1][0] == '-')
	{
		path = get_envar(ministruct->envars, "OLDPWD");
		if (path == NULL)
			return (print_error("cd", NULL, "OLDPWD not set", 1), 0);
	}
	else
		path = args[1];
	oldpwd = get_envar(ministruct->envars, "PWD");
	if (chdir(path) == -1)
		return (print_error_errno("cd", path), 0);
	path = getcwd(NULL, 0);
	ministruct->envars = edit_env(ministruct->envars, "OLDPWD", oldpwd);
	ministruct->envars = edit_env(ministruct->envars, "PWD", path);
	return (free(path), 1);
}
