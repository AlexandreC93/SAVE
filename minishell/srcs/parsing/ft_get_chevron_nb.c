/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_chevron_nb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:13:03 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/10/29 22:29:37 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_chevron_nb(char *line)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (line[i])
	{
		if (ft_ischevron(line[i]))
			nb++;
		i++;
	}
	return (nb);
}
