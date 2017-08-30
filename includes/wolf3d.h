/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 11:17:53 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/30 17:54:41 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdio.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

# define PLAYER 2
# define SS 0
# define WALL 64.0
# define PLAYERSIZE 32
# define FOV 60.0
# define HEIGHT 720
# define LEN 840
# define RADIANCONV 0.017453292
# define MAKE_AMERICA_GREAT_AGAIN 0
# define AVERAGE(a, b)   ( ((((a) ^ (b)) & 0xfffefefeL) >> 1) + ((a) & (b)) )

typedef struct		s_data
{
	char			**map;
	int				map_size;
	float			posx;
	float			posy;
	float			px;
	float			py;
	int				distpp;
	float			angle_ray;
	float			alpha;
	float			ax;
	float			ay;
	float			bx;
	float			by;
	int				height;
	float			beta;
	int				wally;
	int				wallx;
	int				color;
	int				color1;
	int				color2;
	int				color3;
	int				color4;
	int				color5;
	int				color6;
}					t_data;

typedef struct		s_env
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
	unsigned int	*img_cpy;
	t_data			*dat;
}					t_env;

int					parse(t_data *data, char *filename);
void				init_data(t_data *data);
void				init_mlx(t_env *env);
void				find_the_wall(t_data *data, t_env *env);
float				set_degree(float deg);
void				draw_wall(t_data *data, t_env *env);
void				put_mlx(t_env *env, int i);
int					my_key_func(int keycode, t_env *env);
int					mouse_hook_escape(t_env *env);
int					mouse_hook_color(int button, int x, int y, t_env *env);
void				color(t_env *env);
void				color_wall(t_env *env);
void				color_ground(t_env *env);
void				color_sky(t_env *env);
void				set_color_red(t_env *env, int i);
void				set_color_orange(t_env *env, int i);
void				set_color_blue_light(t_env *env, int i);
void				set_color_blue_dark(t_env *env, int i);
void				set_color_purple(t_env *env, int i);
void				set_color_white(t_env *env, int i);
void				set_color_pink(t_env *env, int i);
void				set_color_green(t_env *env, int i);
void				init_color(t_env *env);
void				move_forward(t_env *env);
void				move_back(t_env *env);
void				move_left(t_env *env);
void				move_right(t_env *env);
void				draw_env(t_env *env, t_data *data);
void				go_to_night(t_env *env);
void				go_to_day(t_env *env);
void				reset_img(char *data, int x_max, int y_max);
void				anti_aliasing_wolf(t_env *e, unsigned int *img_temp);
#endif
