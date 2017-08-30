/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_the_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:42:17 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/30 17:38:57 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			ft_wall_height(t_data *data, float dist1, float angle)
{
	float	nice_dist;

	nice_dist = 0;
	nice_dist = dist1 * cos(angle * M_PI / 180);
	data->height = (WALL / fl_to_int(nice_dist) * data->distpp);
}

static int		wall_color(float x, float y, t_data *data)
{
	float	xa;
	float	ya;
	int		temp;
	int		tempi;

	while (data->map[(int)data->ax /
			(int)WALL][(int)data->ay / (int)WALL] == '1')
	{
		data->ax -= 0.05 * cos(data->beta * M_PI / 180);
		data->ay -= 0.05 * sin(data->beta * M_PI / 180) * -1;
	}
	xa = x - cos(data->beta * M_PI / 180);
	ya = y - sin(data->beta * M_PI / 180) * -1;
	temp = (int)(x) / (int)WALL;
	tempi = (int)(y) / (int)WALL;
	if (temp == (int)(xa + 1) / (int)WALL && tempi == (int)(ya) / (int)WALL)
		data->color = data->color1;
	if (tempi == (int)(ya + 1) / (int)WALL && temp == (int)(xa) / (int)WALL)
		data->color = data->color2;
	if (tempi == (int)(ya - 1) / (int)WALL && temp == (int)(xa) / (int)WALL)
		data->color = data->color3;
	if (temp == (int)(xa - 1) / (int)WALL && tempi == (int)(ya) / (int)WALL)
		data->color = data->color4;
	return (1);
}

int				ft_iswall(t_data *data, float x, float y)
{
	int		temp;
	int		tempi;

	temp = (int)(x) / (int)WALL;
	tempi = (int)(y) / (int)WALL;
	if (temp < 0.5 || temp >= data->map_size - 1.5 || tempi < 0.5 || \
			tempi > data->map_size - 0.5)
		return (wall_color(x, y, data));
	if ((data->map[temp][tempi] == '1' || temp < 0.5 || tempi < 0.5)
			&& (int)(x / WALL) >= 0 && (int)(y / WALL) >= 0 && (int)(x / WALL)
				<= data->map_size - 1 && (int)(y / WALL) <= data->map_size - 1)
		return (wall_color(x, y, data));
	return (0);
}

void			ft_check(t_data *data)
{
	data->ax = data->posx + (data->posy - ((data->posy / WALL) * WALL))
		* cos(data->beta * M_PI / 180);
	data->ay = data->posy + (data->posx - ((data->posx / WALL) * WALL))
		* sin(data->beta * M_PI / 180) * -1;
	while (ft_iswall(data, data->ax, data->ay) == 0)
	{
		data->ax += cos(data->beta * M_PI / 180);
		data->ay += sin(data->beta * M_PI / 180) * -1;
	}
}

void			find_the_wall(t_data *data, t_env *env)
{
	float	dist1;
	float	angle;

	draw_env(env, data);
	data->beta = data->alpha + FOV / 2;
	data->beta = set_degree(data->beta);
	angle = FOV / 2;
	data->wallx = 0;
	while (angle >= -30)
	{
		ft_check(data);
		dist1 = sqrt((pow(data->posx - data->ax, 2)) +
		(pow(data->posy - data->ay, 2)));
		dist1 = fabs(dist1);
		ft_wall_height(data, dist1, angle);
		draw_wall(data, env);
		env->dat->beta -= data->angle_ray;
		data->beta = set_degree(data->beta);
		data->wallx++;
		angle -= data->angle_ray;
	}
	anti_aliasing_wolf(env, env->img_cpy);
}
