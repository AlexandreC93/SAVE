/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:11:30 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/10/29 19:08:40 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset(char **args, t_env *envars, t_minishell *ministruct)
{
	if (!args[1])
	{
		print_error("unset", NULL, "not enough arguments", 1);
		return (0);
	}
	ministruct->envars = remove_env(envars, args[1]);
	return (1);
}
