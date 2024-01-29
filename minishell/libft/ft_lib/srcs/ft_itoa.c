/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:00:03 by dkeraudren        #+#    #+#             */
/*   Updated: 2023/02/20 20:51:49 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"
#include <stdio.h>

static void	fill_itoa(char *to_fill, int n, int index)
{
	if (n >= 10 || n <= -10)
	{
		fill_itoa(to_fill, n / 10, index - 1);
		if (n < 0)
			to_fill[index] = -(n % 10) + '0';
		else
			to_fill[index] = (n % 10) + '0';
	}
	else
	{
		if (n < 0)
			to_fill[index] = -n + '0';
		else
			to_fill[index] = n + '0';
	}
}

static int	get_size(int n)
{
	int	size;

	size = 0;
	while (n >= 10 || n <= -10)
	{
		size++;
		n /= 10;
	}
	return (size + 1);
}

char	*ft_itoa(int n)
{
	int		neg;
	int		len;
	int		index;
	char	*ret_val;

	neg = 0;
	index = 0;
	if (n < 0)
		neg = 1;
	len = get_size(n) + neg;
	ret_val = malloc((len + 1) * sizeof(char));
	if (ret_val == NULL)
		return (NULL);
	if (neg)
		ret_val[index] = '-';
	fill_itoa(ret_val, n, len - 1);
	ret_val[len] = '\0';
	return (ret_val);
}
