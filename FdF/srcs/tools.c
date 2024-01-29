/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:57:49 by lcadinot          #+#    #+#             */
/*   Updated: 2023/01/26 17:57:52 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	check_map(const char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("open error", 1);
	get_next_line(fd, &line);
	if (*line == '\0')
	{
		if (close(fd) == -1)
			ft_error("close error", 1);
		free(line);
		ft_error("invalid map (empty)", 0);
	}
	free(line);
	return (1);
}

void	ft_free(int i, char **num, char *line, t_fdf *env)
{
	while (num[i])
		free(num[i++]);
	free(num);
	free(line);
	ft_close(env);
}
