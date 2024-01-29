/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:57:49 by lcadinot          #+#    #+#             */
/*   Updated: 2023/01/26 17:57:52 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/get_next_line/get_next_line_bonus.h"
# include "./libft/libft.h"
# include "./mlx_linux/minilibx-linux/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <errno.h>

# define WIDTH 1920
# define HEIGHT 1080

# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126
# define MINUS 27
# define PLUS 24
# define SPACE 65
# define KEY_R 27
# define MOUSE_CLICK_LEFT 1
# define MOUSE_CLICK_RIGHT 3
# define MOUSE_CLICK_MIDDLE 2
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define ESCAPE 9
# define M_PI 3.14159265358979323846

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
	int	reverse;
}	t_point;

typedef struct s_map
{
	int	height;
	int	width;
	int	***array;
	int	z_max;
	int	z_min;
	int	flag;
}	t_map;

typedef struct s_camera
{
	int		zoom;
	double	x_angle;
	double	y_angle;
	double	z_angle;
	float	z_height;
	int		x_offset;
	int		y_offset;
	int		iso;
}	t_camera;

typedef struct s_mouse
{
	int	button;
	int	x;
	int	y;
	int	prev_x;
	int	prev_y;
}	t_mouse;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data_addr;
	int			bpp;
	int			size_line;
	int			endian;
	int			steep;
	t_map		*map;
	t_camera	*camera;
	t_mouse		*mouse;
}	t_fdf;

int		ft_height(char *filename);
int		ft_width(char *filename);
void	ft_check(char *filename, t_map *map, t_fdf *env);
void	ft_draw(t_map *map, t_fdf *env);
void	ft_pixel(t_fdf *env, int x, int y, int color);
void	ft_draw_line(t_point s, t_point e, t_fdf *env);
t_point	project(int x, int y, t_fdf *env);
int		ft_min(int a, int b);
int		get_default_color(int z, t_map *map);
void	ft_error(const char *err_msg, int system_function);
double	ft_reset_angles(double angle);
int		check_map(const char *filename);
void	ft_free(int i, char **num, char *line, t_fdf *env);
t_map	*ft_map_init(void);

float	ft_abs(float n);
int		ft_ipart(float n);
float	ft_fpart(float n);
float	ft_rfpart(float n);

void	ft_hook_controls(t_fdf *env);
int		ft_key(int keycode, void *params);
int		ft_mouse_down(int button, int x, int y, void *params);
int		ft_mouse_up(int button, int x, int y, void *params);
int		ft_mouse_move(int x, int y, void *params);
int		ft_close(void *params);

#endif
