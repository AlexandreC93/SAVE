/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:37:41 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/04/08 16:28:59 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_strjoin(char *left_str, char *buff)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (!left_str)
	{
		left_str = malloc(sizeof(char));
		if (!left_str)
			return (NULL);
		left_str[0] = '\0';
	}
	if (!buff)
		return (NULL);
	new_str = malloc(sizeof(char)
			* (ft_strlen(left_str) + ft_strlen(buff) + 1));
	if (!new_str)
		return (NULL);
	i = -1;
	while (left_str[++i])
		new_str[i] = left_str[i];
	j = 0;
	while (buff[j])
		new_str[i++] = buff[j++];
	new_str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	return (free(left_str), new_str);
}

char	*ft_get_line_bis(char *line, size_t i)
{
	if (i == 0)
		return (free(line), NULL);
	line[i] = '\0';
	return (line);
}

char	*ft_get_line(char *left_str)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!left_str)
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		line[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		line[i] = left_str[i];
		i++;
	}
	return (ft_get_line_bis(line, i));
}
