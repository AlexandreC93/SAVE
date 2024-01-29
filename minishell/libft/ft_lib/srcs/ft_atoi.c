/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:41:34 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/02/20 20:51:49 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

int	ft_atoi(const char *nptr)
{
	int	index;
	int	retval;
	int	neg;

	index = 0;
	retval = 0;
	neg = 1;
	while (' ' == nptr[index] || '\f' == nptr[index] || '\n' == nptr[index]
		|| '\r' == nptr[index] || '\v' == nptr[index] || '\t' == nptr[index])
			index++;
	if (nptr[index] == '-' || nptr[index] == '+')
	{
		if (nptr[index] == '-')
			neg *= -1;
		index++;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		retval = retval * 10 + ((nptr[index] - '0') * neg);
		index++;
	}
	return (retval);
}
