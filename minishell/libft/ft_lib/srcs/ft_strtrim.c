/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:30:22 by dkeraudren        #+#    #+#             */
/*   Updated: 2023/02/20 20:51:49 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

static int	check_in_set(char to_check, char const *set)
{
	int	index;

	index = 0;
	while (set[index])
	{
		if (to_check == set[index])
			return (1);
		index++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*to_alloc;
	size_t	start;
	size_t	end;
	size_t	index;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && check_in_set(s1[start], set))
		start++;
	while (end > start && check_in_set(s1[end - 1], set))
		end--;
	if (start == end)
		return (ft_strdup(""));
	to_alloc = (char *)malloc(sizeof(*to_alloc) * ((end - start) + 1));
	if (!to_alloc)
		return (NULL);
	index = 0;
	while (start < end)
		to_alloc[index++] = s1[start++];
	to_alloc[index] = '\0';
	return (to_alloc);
}
