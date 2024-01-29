/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:03:47 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/10/29 19:53:51 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_quotes(const char *buffer)
{
	int		i;
	char	c;
	int		flag;

	i = 0;
	flag = 1;
	c = '\0';
	while (buffer[i])
	{
		if ((buffer[i] && (buffer[i] == '\"'
					|| buffer[i] == '\'') && flag != 0))
		{
			flag = 0;
			c = buffer[i++];
		}
		if (buffer[i] == c && buffer[i])
			flag = 1;
		i++;
	}
	if (flag == 1)
		return (1);
	ft_putstr_fd("minishell: syntax error\n", STDERR_FILENO);
	g_status = 2;
	return (0);
}
