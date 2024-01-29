/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:50:08 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/10/30 16:56:12 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_env(t_env *envars)
{
	while (envars->next)
	{
		ft_printf("%s=%s\n", envars->key, envars->value);
		envars = envars->next;
	}
	return (0);
}

void	print_error(char *exe, char *arg, char *error, int exit_code)
{
	ft_putstr_fd("minishell", 2);
	if (exe)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(exe, 2);
	}
	if (arg)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(arg, 2);
	}
	if (error)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(error, 2);
	}
	ft_putstr_fd("\n", 2);
	g_status = exit_code;
}

void	print_error_errno(char *exe, char *arg)
{
	print_error(exe, arg, strerror(errno), 126);
	errno = 0;
}
