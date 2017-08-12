/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 11:17:53 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/12 12:07:28 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H 
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
}               t_data;

typedef struct  s_env
{
    void			*mlx;
	void			*win;
	void			*img;
	int				bpp;
	int				sizeline;
	int				endian;
	char			*data;
	t_data			*dat;
}               t_env;

int			parse(t_data *data, char *filename);
void		init_data(t_data *data);
void		init_mlx(t_env *env);
void		find_the_wall(t_data *data, t_env *env);
double		set_degree(double deg);
void		draw_wall(t_data *data, t_env *env);
void		put_mlx(t_env *env);
int     	my_key_func(int keycode, t_env *env);
void		move_forward(t_env *env);
void		move_back(t_env *env);
void		move_left(t_env *env);
void		move_right(t_env *env);
void    	draw_env(t_env *env, t_data *data);

#endif