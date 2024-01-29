/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:44:56 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/02/20 21:47:42 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

char	*ft_itoa_base(unsigned long long n, char *base)
{
	int					len;
	unsigned long long	nb;
	char				*s;

	len = 0;
	nb = n;
	if (nb == 0)
		len = 1;
	while (nb > 0)
	{
		nb /= ft_strlen(base);
		len++;
	}
	s = malloc(sizeof(char) * (len + 1));
	s[len] = '\0';
	while (len > 0)
	{
		s[len - 1] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
		len--;
	}
	return (s);
}
