/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:57:49 by lcadinot          #+#    #+#             */
/*   Updated: 2023/01/26 17:57:52 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	ft_draw_instructions(t_fdf *env)
{
	mlx_string_put(env->mlx, env->win, 5, 100, 0xFFFFFF,
		"R:            Reset");
	mlx_string_put(env->mlx, env->win, 5, 60, 0xFFFFFF,
		"Middle Click: Rotate z");
	mlx_string_put(env->mlx, env->win, 5, 20, 0xFFFFFF,
		"Left Click:   Translate");
	mlx_string_put(env->mlx, env->win, 5, 40, 0xFFFFFF,
		"Right Click:  Rotate x/y");
	if (env->camera->iso)
		mlx_string_put(env->mlx, env->win, 5, 80, 0xFFFFFF,
			"Space:        Toggle projection (Current: Isometric)");
	else
		mlx_string_put(env->mlx, env->win, 5, 80, 0xFFFFFF,
			"Space:        Toggle projection (Current: Parrallel)");
	mlx_string_put(env->mlx, env->win, 5, 120, 0xFFFFFF,
		"-/+:          Flatten");
}

void	ft_draw(t_map *map, t_fdf *env)
{
	int	x;
	int	y;

	ft_bzero(env->data_addr, WIDTH * HEIGHT * (env->bpp / 8));
	y = 0;
	if (env->camera->x_angle > 0)
		y = map->height - 1;
	while (y < map->height && y >= 0)
	{
		x = 0;
		if (env->camera->y_angle > 0)
			x = map->width - 1;
		while (x < map->width && x >= 0)
		{
			if (x != map->width - 1)
				ft_draw_line(project(x, y, env), project(x + 1, y, env), env);
			if (y != map->height - 1)
				ft_draw_line(project(x, y, env), project(x, y + 1, env), env);
			x += -2 * (env->camera->y_angle > 0) + 1;
		}
		y += -2 * (env->camera->x_angle > 0) + 1;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	ft_draw_instructions(env);
}
