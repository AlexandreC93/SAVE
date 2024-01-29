/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execvp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:35:24 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/10/30 17:13:45 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*parse_path(char **splited_path, char *exe)
{
	int		i;
	char	*potential_exe_dir;
	char	*potential_exe_path;

	i = 0;
	while (splited_path[i])
	{
		potential_exe_dir = ft_strjoin(splited_path[i], "/");
		potential_exe_path = ft_strjoin(potential_exe_dir, exe);
		free(potential_exe_dir);
		if (access(potential_exe_path, X_OK) == 0)
		{
			ft_free_2d_list(splited_path);
			return (potential_exe_path);
		}
		free(potential_exe_path);
		i++;
	}
	return (NULL);
}

char	*find_exe_path(char *exe, char *path_envar)
{
	char	**splited_path;
	char	*potential_exe_path;

	if (!path_envar)
		return (NULL);
	splited_path = ft_split(path_envar, ':');
	if (!splited_path)
		return (NULL);
	potential_exe_path = parse_path(splited_path, exe);
	if (potential_exe_path)
		return (potential_exe_path);
	ft_free_2d_list(splited_path);
	return (NULL);
}

int	exec_absolute(t_command *cmd)
{
	int		ret;
	char	**envp;

	envp = build_env(cmd->envars);
	ret = execve(cmd->argv[0], cmd->argv, envp);
	ft_free_2d_list(envp);
	return (ret);
}

int	ft_execvp(t_command *cmd, int fd_in, int fd_out)
{
	char		*exe_path;
	int			i;
	int			ret;
	struct stat	path_stat;
	char		**envp;

	exe_path = NULL;
	i = 0;
	if (stat(cmd->argv[0], &path_stat) == 0 && S_ISDIR(path_stat.st_mode))
		return (errno = 21, 126);
	while (cmd->argv[0] && cmd->argv[0][i++])
		if (cmd->argv[0][i] == '/')
			return (exec_absolute(cmd));
	if (cmd->argv[0])
	{
		if (is_builtin(cmd->argv[0]))
			return (redirect_builtin(cmd, cmd->mini_struct, fd_in, fd_out), 0);
		exe_path = find_exe_path(cmd->argv[0], get_envar(cmd->envars, "PATH"));
	}
	if (!cmd->argv[0] || !exe_path || stat(exe_path, &path_stat) == -1)
		return (127);
	envp = build_env(cmd->envars);
	ret = execve(exe_path, cmd->argv, envp);
	ft_free_2d_list(envp);
	return (free(exe_path), ret);
}
