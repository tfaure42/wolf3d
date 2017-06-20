/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 11:17:53 by tfaure            #+#    #+#             */
/*   Updated: 2017/06/20 12:54:49 by tfaure           ###   ########.fr       */
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
# define WALL 64
# define PLAYERSIZE 32
# define FOV 60.0
# define HEIGHT 200
# define LEN 320
# define RADIANCONV 0.017453292
# define MAKE_AMERICA_GREAT_AGAIN 0

typedef struct  s_data
{
	char	**map;
	int		map_size;
	double	posx;
	double	posy;
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
}               t_env;

int			parse(t_data *data, char *filename);
void		init_data(t_data *data);
void		init_mlx(t_env *env);
void		find_the_wall(t_data *data, t_env *env);
double		set_degree(double deg);
void		draw_wall(t_data *data, t_env *env);

#endif