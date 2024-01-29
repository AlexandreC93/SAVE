/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:40:32 by dkeraudren        #+#    #+#             */
/*   Updated: 2023/02/20 20:51:49 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*to_alloc;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (__SIZE_MAX__ / size < nmemb)
		return (0);
	to_alloc = malloc(nmemb * size);
	if (!to_alloc)
		return (NULL);
	ft_bzero(to_alloc, nmemb * size);
	return (to_alloc);
}
