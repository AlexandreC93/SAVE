/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:01:19 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/10/30 21:32:24 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	export(char **args, t_env *envars, t_minishell *ministruct)
{
	char	**splited_arg;

	if (!args[1])
	{
		print_env(envars);
	}
	else if (ft_strchr(args[1], '='))
	{
		splited_arg = ft_split(args[1], '=');
		if (splited_arg[0] && splited_arg[1])
			ministruct->envars = edit_env(envars,
					splited_arg[0], splited_arg[1]);
		ft_free_2d_list(splited_arg);
	}
	return (1);
}
