/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:54:49 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/02/20 20:51:49 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

char	*ft_strrchr(const char *s, int c)
{
	int	index;

	index = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + index);
	while (index >= 0)
	{
		if (s[index] == (char)c)
			return ((char *)s + index);
		index--;
	}
	return (NULL);
}
