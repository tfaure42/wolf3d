/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 11:17:53 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/17 13:46:22 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H 
# include <stdio.h>
# include <mlx.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

# define PLAYER 2
# define WALL 64.0
# define PLAYERSIZE 32
# define FOV 60.0
# define HEIGHT 720
# define LEN 960
# define RADIANCONV 0.017453292
# define MAKE_AMERICA_GREAT_AGAIN 0

typedef struct  s_data
{
	char	**map;
	int		map_size;
	double	posx;
	double	posy;
	double	px;
	double	py;
	int		distpp;
	double  angle_ray;
	double	alpha;
	double	ax;
	double	ay;
	double	bx;
	double	by;
	int		height;
	double	beta;
	int		wally;
	int		wallx;
	int		color;
	int		color1;
	int		color2;
	int		color3;
	int		color4;
	int		color5;
	int		color6;
}               t_data;

typedef struct  s_env
{
    void			*mlx;
	void			*win;
	void			*win2;
	void			*img;
	void			*img2;
	int				bpp;
	int				sizeline;
	int				endian;
	char			*data;
	char			*data2;
	t_data			*dat;
}               t_env;

int			parse(t_data *data, char *filename);
void		init_data(t_data *data);
void		init_mlx(t_env *env);
void		find_the_wall(t_data *data, t_env *env);
double		set_degree(double deg);
void		draw_wall(t_data *data, t_env *env);
void		put_mlx(t_env *env, int i);
int     	my_key_func(int keycode, t_env *env);
int			mouse_hook_escape(t_env *env);
int			mouse_hook_color(int button, int x, int y, t_env *env);
void		color(t_env *env);
void		color_wall(t_env *env);
void		color_ground(t_env *env);
void		color_sky(t_env *env);
void		set_color1(t_env *env, int i);
void		init_color(t_env *env);
void		move_forward(t_env *env);
void		move_back(t_env *env);
void		move_left(t_env *env);
void		move_right(t_env *env);
void    	draw_env(t_env *env, t_data *data);

#endif
