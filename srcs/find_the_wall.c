/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_the_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 13:21:40 by tfaure            #+#    #+#             */
/*   Updated: 2017/06/20 09:37:35 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		ft_wall_height(t_data *data, double dist1)
{
	dist1 = dist1 * cos(data->beta * RADIANCONV);
	data->height = (WALL / dist1) * data->distpp;
}

int		ft_iswall(t_data *data, double x, double y)
{
	
	if (data->map[(int)x / WALL][(int)y / WALL] == '1')
		return (1);
	return (0);
}

void	ft_horizontal(t_data *data)
{
	int	ya;
	int	xa;

	if (data->alpha <= 180)
		data->ay = (int)(data->posy / WALL) * WALL - 1;
	else
		data->ay = (int)(data->posy / WALL) * WALL + WALL;
	data->ax = data->posx + (data->posy - data->ay) / tan(data->beta * RADIANCONV);
	
	if (data->alpha <= 180)
		ya = WALL;
	else
		ya = -WALL;
	
	xa = WALL / tan(data->beta * RADIANCONV);
	
	while (ft_iswall(data, data->ax, data->ay) == 0)
	{
		data->ax = data->ax + xa;
		data->ay = data->ay + ya;
	}
}

void	ft_vertical(t_data *data)
{
	int ya;
	int	xa;

	if (data->alpha <= 90 || data->alpha >= 270)
		data->bx = (int)(data->posx / WALL) * WALL + 64;
	else
		data->bx = (int)(data->posy / WALL) * WALL - 1;
	data->by = data->posy + (data->posx - data->bx) * tan(data->beta * RADIANCONV); 
	if (data->alpha <= 90 || data->alpha >= 270)
		xa = WALL;
	else
		xa = -WALL;
	ya = WALL * tan(data->beta * RADIANCONV);
	while (ft_iswall(data, data->bx, data->by) == 0)
	{
		data->bx = data->bx + xa;
		data->by = data->by + ya;
	}
}

void	find_the_wall(t_data *data, t_env *env)
{
	double	dist1;
	double	dist2;

	data->beta = data->alpha - 30;
	data->beta = set_degree(data->beta);
	while (data->beta != (data->alpha + 30))
	{
    	ft_horizontal(data);
    	ft_vertical(data);
		dist1 = sqrt(pow(data->posx - data->ax, 2) + pow(data->posy - data->ay, 2));
		dist2 = sqrt(pow(data->posx - data->bx, 2) + pow(data->posy - data->by, 2));
		dist1 = dist1 < dist2 ? dist1 : dist2;
		ft_wall_height(data, dist1);
		// trace le putain de mur
		data->beta += data->angle_ray;
		// printf("angleray = %f\nbeta = %f\n",data->angle_ray, data->beta);
	}
}