/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:37:30 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/04/08 16:22:38 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_rest_str(char *rest_str)
{
	char	*new_rest_str;
	size_t	i;
	size_t	j;

	i = 0;
	while (rest_str[i] && rest_str[i] != '\n')
		i++;
	if (!rest_str[i])
	{
		free(rest_str);
		return (NULL);
	}
	new_rest_str = malloc(sizeof(char) * (ft_strlen(rest_str) - i + 1));
	if (!new_rest_str)
		return (NULL);
	i++;
	j = 0;
	while (rest_str[i])
		new_rest_str[j++] = rest_str[i++];
	new_rest_str[j] = '\0';
	free(rest_str);
	return (new_rest_str);
}

void	ft_strcpy(char *src, char *dest)
{
	size_t	index;

	index = 0;
	if (!src)
	{
		dest[0] = '\0';
		return ;
	}
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
}

char	*ft_read_line(int fd, char *rest_str)
{
	char	*buff;
	int		ret;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	ret = 1;
	while (!ft_strchr(rest_str, '\n') && ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buff);
			free(rest_str);
			return (NULL);
		}
		buff[ret] = '\0';
		rest_str = ft_gnl_strjoin(rest_str, buff);
	}
	free(buff);
	return (rest_str);
}

char	*get_next_line(int fd)
{
	static char	rest_str[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	char		*tmp;

	if (fd < 0 || fd > 16 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = malloc(sizeof(char) * (ft_strlen(rest_str[fd]) + 1));
	if (!tmp)
		return (NULL);
	ft_strcpy(rest_str[fd], tmp);
	tmp = ft_read_line(fd, tmp);
	if (!tmp)
		return (NULL);
	line = ft_get_line(tmp);
	tmp = ft_get_rest_str(tmp);
	ft_strcpy(tmp, rest_str[fd]);
	free(tmp);
	return (line);
}
