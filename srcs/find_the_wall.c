/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_the_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 13:21:40 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/14 08:41:26 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		ft_wall_height(t_data *data, double dist1, double angle)
{
	double		nice_dist;

	nice_dist = 0;
	nice_dist = dist1 * cos(angle * M_PI / 180);
	data->height = (WALL / nice_dist * data->distpp);
}

int		ft_iswall(t_data *data, double x, double y)
{
	double xa;
	double ya;

	xa = x - cos(data->beta * M_PI / 180);
	ya = y - sin(data->beta * M_PI / 180) * -1;
	// if ((int)x / WALL < 0 || (int)y / WALL < 0 || (int)x / WALL > data->map_size-1 || (int)y / WALL > data->map_size-1)
	// {
	// 	data->color = 0;
	// 	return(1);
	// }
	// if ((int)x / WALL == 0 || (int)y / WALL == 0 || (int)x / WALL == data->map_size-1 || (int)y / WALL == data->map_size-1)
	// {
	// 	data->color = 0x555555;
	// 	return(1);
	// }
	if (data->map[fl_to_int(x) / (int)WALL][fl_to_int(y) / (int)WALL] == '1' || (int)x / WALL < 0 || (int)y / WALL < 0 || (int)x / WALL > data->map_size-1 || (int)y / WALL > data->map_size-1)
		{
			if (fl_to_int(x) / (int)WALL == fl_to_int(xa + 1) / (int)WALL && fl_to_int(y) / (int)WALL == fl_to_int(ya) / (int)WALL)
			data->color = 0xBCA9F5;
			if (fl_to_int(y) / (int)WALL == fl_to_int(ya + 1) / (int)WALL && fl_to_int(x) / (int)WALL == fl_to_int(xa) / (int)WALL)
			data->color = 0xAE95F8;
			if (fl_to_int(x) / (int)WALL == fl_to_int(xa - 1) / (int)WALL && fl_to_int(y) / (int)WALL == fl_to_int(ya) / (int)WALL)
			data->color = 0x8D6AF7;
			if (fl_to_int(y) / (int)WALL == fl_to_int(ya - 1) / (int)WALL && fl_to_int(x) / (int)WALL == fl_to_int(xa) / (int)WALL)
			data->color = 0x9F81F7;
			return (1);
		}
		
	return (0);
}

void	ft_check(t_data *data)
{
	data->ax = data->posx + (data->posy - ((data->posy / WALL) * WALL)) * cos(data->beta * M_PI / 180);
	data->ay = data->posy + (data->posx - ((data->posx / WALL) * WALL)) * sin(data->beta * M_PI / 180) * -1;
	while (ft_iswall(data, data->ax, data->ay) == 0)
	{
		data->ax += cos(data->beta * M_PI / 180);
		data->ay += sin(data->beta * M_PI / 180) * -1;
	}
}

void	find_the_wall(t_data *data ,t_env *env)
{
	int	dist1;
	double	angle;

	draw_env(env, data);
	data->beta = data->alpha + FOV / 2;
	data->beta = set_degree(data->beta);
	angle = FOV / 2;
	data->wallx = 0;
	while (angle >= -30)
	{
    	ft_check(data);
		dist1 = sqrt((int)pow(data->posx - data->ax, 2) + (int)pow(data->posy - data->ay, 2));
		dist1 = abs(dist1);
		ft_wall_height(data, dist1, angle);
		draw_wall(data, env);
		data->beta -= data->angle_ray;
		data->beta = set_degree(data->beta);
		data->wallx++;
		angle -= data->angle_ray;
	}
}
