/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_the_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 13:21:40 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/11 12:37:48 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		ft_wall_height(t_data *data, double dist1, double angle)
{
	double		nice_dist;

	nice_dist = 0;
	nice_dist = dist1  * cos(angle * M_PI / 180);
	// printf("dist1= %f\n", nice_dist);
	data->height = (WALL / nice_dist * data->distpp);
	// printf("wallheight = %d\n", data->height);
}

int		ft_iswall(t_data *data, double x, double y)
{
	//printf("x = %d, y = %d\n",(int)x / WALL , (int)y / WALL);//, data->map[(int)x / WALL][(int)y/WALL]);
	data->color = 0x000000;
	if ((int)x / WALL < 0 || (int)y / WALL < 0 || (int)x / WALL > data->map_size-1 || (int)y / WALL > data->map_size-1)
	{
		// printf("yoyo");
		data->color = 0;
		return(1);
	}
	if ((int)x / WALL == 0 || (int)y / WALL == 0 || (int)x / WALL == data->map_size-1 || (int)y / WALL == data->map_size-1)
	{
		// printf("no wall found\n");
		data->color = 0xFF0000;
		return(1);
	}
	if (data->map[(int)x / (int)WALL][(int)y / (int)WALL] == '1')
		{
			data->color = 0x00FF00;
			return (1);
		}
		data->color = 0x000000;
	// printf("x = %d, y = %d, map = %c\n",(int)x / WALL , (int)y / WALL, data->map[(int)x / WALL][(int)y/WALL]);
	return (0);
}

void	ft_check(t_data *data)
{
	if ((int)(data->beta / 180) % 2 == 0)
		data->ay = (int)(data->posy / WALL) * WALL;
	else if ((int)(data->beta / 180) % 2 == 1)
		data->ay = (int)(data->posy / WALL) * WALL;
	// printf("tan = %f\n", tan(data->beta * M_PI / 180));
	data->ax = data->posx + (data->posy - data->ay) * cos(data->beta * M_PI / 180);
	// printf("ax = %f\n", data->ax);
	while (ft_iswall(data, data->ax, data->ay) == 0)
	{
		data->ax = data->ax + cos(data->beta * M_PI / 180);
		data->ay = data->ay + sin(data->beta * M_PI / 180) * -1;
	}
}

void	find_the_wall(t_data *data ,t_env *env)
{
	int	dist1;
	double	angle;

	draw_env(env, data);
	data->beta = data->alpha + 30;
	data->beta = set_degree(data->beta);
	angle = 30;
	// printf("beta = %f\n", data->beta);
	data->wallx = 0;
	while (angle != -30)
	{
		// printf("\nhoriz\n");
    	ft_check(data);
		// printf("\ndist calc\n");
		dist1 = sqrt((int)pow(data->posx - data->ax, 2) + (int)pow(data->posy - data->ay, 2));
		// printf("dist1 = %d",dist1);
		dist1 = abs(dist1);
		// printf(", dist2 = %d, shortest = %d\n",dist2, dist1);
		ft_wall_height(data, dist1, angle);
		draw_wall(data, env);
		// printf("\nincrement\n");
		data->beta -= data->angle_ray;
		data->beta = set_degree(data->beta);
		data->wallx++;
		angle -= data->angle_ray;
		// printf("\nangleray = %f\nbeta = %f\n",data->angle_ray, data->beta);
	}
}