/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <lcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:28:23 by lcadinot          #+#    #+#             */
/*   Updated: 2023/08/10 22:31:37 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	some_error(char *str)
{
	if (str)
		free(str);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	int			rd;
	static char	*rem;

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (some_error(rem));
	rd = 1;
	while (!find_nl(rem) && rd > 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd < 0)
			return (some_error(buf));
		buf[rd] = '\0';
		rem = str_join(rem, buf);
	}
	free(buf);
	*line = get_line(rem);
	rem = trim_rem(rem);
	if (rd == 0 && !rem)
		return (0);
	return (1);
}
