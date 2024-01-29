/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:18:24 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/10/27 20:05:28 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

size_t	ft_strlen(const char *s)
{
	int	index;

	index = 0;
	if (!s)
		return (0);
	while (s[index])
	{
		index++;
	}
	return (index);
}
