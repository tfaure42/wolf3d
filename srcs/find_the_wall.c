/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_the_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 13:21:40 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/24 13:46:08 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	ft_wall_height(t_data *data, double dist1, double angle)
{
	double	nice_dist;

	nice_dist = 0;
	nice_dist = dist1 * cos(angle * M_PI / 180);
	data->height = (WALL / fl_to_int(nice_dist) * data->distpp);
}

static int	mathilde_est_une_pute(int temp, int tempi, int xa, int ya, t_data *data)
{
	if (temp == (int)(xa + 1) / (int)WALL && tempi == (int)(ya) / (int)WALL)
		data->color = data->color1;
	if (tempi == (int)(ya + 1) / (int)WALL && temp == (int)(xa) / (int)WALL)
		data->color = data->color2;
	if (tempi == (int)(ya - 1) / (int)WALL && temp == (int)(xa) / (int)WALL)
		data->color = data->color3;
	if (temp == (int)(xa - 1) / (int)WALL && tempi == (int)(ya) / (int)WALL)
		data->color = data->color4;
		return(1);
}

int		ft_iswall(t_data *data, double x, double y)
{
	double xa;
	double ya;
	int		temp;
	int 	tempi;

	xa = x - cos(data->beta * M_PI / 180);
	ya = y - sin(data->beta * M_PI / 180) * -1;
	
	temp = (int)(x) / (int)WALL;
	tempi = (int)(y) / (int)WALL;
	if(temp < 0 || temp >= data->map_size - 1 || tempi < 0 || tempi > data->map_size - 1)
		return (mathilde_est_une_pute(temp, tempi, xa, ya, data));
	if (data->map[temp][tempi] == '1'
			&& (int)(x / WALL) >= 0 && (int)(y / WALL) >= 0 && (int)(x / WALL)
				<= data->map_size - 1 && (int)(y / WALL) <= data->map_size - 1)
	return (mathilde_est_une_pute(temp, tempi, xa, ya, data));
//	if ((int)(x / WALL) < 0 && (int)(y / WALL) < 0 && (int)(x / WALL)
//				> data->map_size - 1 && (int)(y / WALL) > data->map_size - 1)
//				return(1);
	return (0);
}

void	ft_check(t_data *data)
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

void	find_the_wall(t_data *data, t_env *env)
{
	double		dist1;
	double	angle;

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
		data->beta -= data->angle_ray;
		data->beta = set_degree(data->beta);
		data->wallx++;
		angle -= data->angle_ray;

	}
}
