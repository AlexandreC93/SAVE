/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:01:51 by lcadinot          #+#    #+#             */
/*   Updated: 2022/12/04 18:10:55 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_this_line(char	*buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, 1);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc(ft_strlen(buffer) - i + 1, 1);
	i++;
	j = 0;
	while (buffer[i] != '\0')
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	int		size;

	size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)ft_calloc((size + 1), 1);
	if (!str || !s1 || !s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[size] = 0;
	return (str);
}

char	*ft_read(int fd, char *res)
{
	int		size;
	char	*buffer;

	size = 1;
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!res)
		res = ft_calloc(1, 1);
	while (size > 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free(buffer);
			free(res);
			return (NULL);
		}
		buffer[size] = 0;
		res = reajoin(res, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_read(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_this_line(buffer[fd]);
	buffer[fd] = ft_next(buffer[fd]);
	return (line);
}
/*
int	main(void)
{
	int	fd;
    int fd2;
    int i = 0;

	char	*s;
    char    *s2;

	fd = open("text.txt", O_RDONLY);
	fd2 = open("text2.txt", O_RDONLY);
	s = get_next_line(fd);
    s2 = get_next_line(fd2);

	while (i < 20)
	{
		printf("%s\n", s);
		free(s);
		s = get_next_line(fd);
        i++;
	}
	write(1, "CHECK", 5);
    i = 0;
	while (i < 20)
	{
		printf("%s\n", s2);
		free(s2);
		s2 = get_next_line(fd2);
        i++;
	}
	printf("%d", BUFFER_SIZE);
	close(fd);
	return (0);
}
*/
