/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:57:49 by lcadinot          #+#    #+#             */
/*   Updated: 2023/01/26 17:57:52 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("open error", 1);
	height = 0;
	while (get_next_line(fd, &line) >= 0 && *line != '\0')
	{
		height++;
		free(line);
	}
	free(line);
	if (close(fd) == -1)
		ft_error("close error", 1);
	return (height);
}

int	ft_width(char *filename)
{
	int		fd;
	int		width;
	char	*line;
	int		i;

	i = -1;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("open error", 1);
	width = 0;
	get_next_line(fd, &line);
	if (*line == '\0')
		ft_error("invalid map (empty)", 0);
	while (line[++i])
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			width++;
	free(line);
	while (get_next_line(fd, &line))
		free(line);
	free(line);
	if (close(fd) == -1)
		ft_error("close error", 1);
	return (width);
}

static void	ft_fill_table(int **n, char *line, int width, t_fdf *env)
{
	char	**num;
	int		i;
	int		j;

	num = ft_split(line, ' ');
	i = -1;
	while (num[++i] && i < width)
	{
		n[i] = malloc(sizeof(int) * 2);
		if (!n[i])
			ft_error("malloc error", 1);
		n[i][0] = ft_atoi(num[i]);
		j = 0;
		while (num[i][j] && num[i][j] != ',')
			j++;
		if (num[i][j] == ',')
			n[i][1] = ft_atoi_base(&num[i][++j], "0123456789ABCDEF");
		else
			n[i][1] = -1;
		free(num[i]);
	}
	if (i != width || num[i])
		ft_free(i, num, line, env);
	free(num);
}

static void	ft_get_z(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->z_min = map->array[0][0][0];
	map->z_max = map->array[0][0][0];
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->array[i][j][0] < map->z_min)
				map->z_min = map->array[i][j][0];
			if (map->array[i][j][0] > map->z_max)
				map->z_max = map->array[i][j][0];
			j++;
		}
		i++;
	}
}

void	ft_check(char *file, t_map *map, t_fdf *env)
{
	int		fd;
	char	*line;
	int		i;

	map->width = ft_width(file);
	map->height = ft_height(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("open error", 1);
	i = -1;
	map->array = malloc(sizeof(int **) * map->height);
	if (!map->array)
		ft_error("malloc error", 1);
	while (get_next_line(fd, &line) >= 0 && *line != '\0')
	{
		map->array[++i] = malloc(sizeof(int *) * map->width);
		if (!map->array[i])
			ft_error("malloc error", 1);
		ft_fill_table(map->array[i], line, map->width, env);
		free(line);
	}
	free(line);
	ft_get_z(map);
	if (close(fd) == -1)
		ft_error("close error", 1);
}
