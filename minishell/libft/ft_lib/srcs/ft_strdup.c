/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:40:35 by dkeraudren        #+#    #+#             */
/*   Updated: 2023/02/20 20:51:49 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

char	*ft_strdup(const char *s)
{
	char	*to_alloc;
	size_t	len;

	len = ft_strlen(s);
	to_alloc = malloc(len + 1);
	if (!to_alloc)
		return (NULL);
	ft_strlcpy(to_alloc, s, len + 1);
	return (to_alloc);
}
