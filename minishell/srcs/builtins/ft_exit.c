/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:42:50 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/10/29 17:59:49 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_all(t_minishell *ministruct)
{
	free_envars(ministruct->envars);
	free_mini_vars(ministruct);
	free(ministruct);
}

unsigned char	ft_atoi_exit(char *str)
{
	unsigned char	nb;
	int				i;
	int				is_neg;

	nb = 0;
	i = 0;
	is_neg = 0;
	if (str[i] == '-')
		is_neg = 1;
	if (ft_issign(str[i]))
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	if (is_neg)
		return (-nb);
	return (nb);
}

void	ft_exit(char **args, t_minishell *ministruct, int tmp_in, int tmp_out)
{
	int	exit_value;

	if (args[1] && args[2])
		return (print_error("exit", NULL, "too many arguments", 1), ((void)0));
	else
	{
		if (args[1])
		{
			if (ft_isnumber(args[1]))
				exit_value = ft_atoi_exit(args[1]);
			else
			{
				print_error("exit", args[1], "numeric argument required", 2);
				exit_value = 2;
			}
		}
		else
			exit_value = errno;
	}
	close(tmp_in);
	close(tmp_out);
	free_all(ministruct);
	exit(exit_value);
}
