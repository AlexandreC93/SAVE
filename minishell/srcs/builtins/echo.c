/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:57:23 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/10/29 19:08:20 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo(char **args)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	if (args[1] && !ft_strncmp(args[1], "-n", 2))
	{
		n = 1;
		i++;
	}
	while (args[i])
	{
		ft_putstr(args[i]);
		if (args[i + 1])
			ft_putchar(' ');
		i++;
	}
	if (!n)
		ft_putchar('\n');
	return (1);
}
