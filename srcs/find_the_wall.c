/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_the_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 13:21:40 by tfaure            #+#    #+#             */
/*   Updated: 2017/06/21 11:46:38 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		ft_wall_height(t_data *data, double dist1, double angle)
{
	double		nice_dist;

	nice_dist = 0;
	nice_dist = dist1  * cos((angle) * RADIANCONV);
	// printf("dist1= %f\n", nice_dist);
	data->height = fl_to_int(WALL / nice_dist * data->distpp);
	// printf("wallheight = %d\n", data->height);
}

int		ft_iswall(t_data *data, double x, double y)
{
	
	if ((int)x / WALL < 0 || (int)y / WALL < 0 || (int)x / WALL >= data->map_size-1 || (int)y / WALL >= data->map_size-1)
		return(1);
	else if (data->map[(int)x / WALL][(int)y / WALL] == '1')
		return (1);
	// printf("x = %d, y = %d, map = %c\n",(int)x / WALL , (int)y / WALL, data->map[(int)x / WALL][(int)y/WALL]);
	return (0);
}

void	ft_horizontal(t_data *data)
{
	int	ya;
	int	xa;

	if (data->beta <= 180)
		data->ay = (int)(data->posy / WALL) * WALL - 1;
	else
		data->ay = (int)(data->posy / WALL) * WALL + 64;
	// printf("ay = %f\n", data->ay);
	data->ax = data->posx + (data->posy - data->ay) * tan(data->beta * RADIANCONV);
	// printf("ax = %f\n", data->ax);
	if (data->beta <= 180)
		ya = -64;
	else
		ya = 64;
	// printf("ya = %d\n", ya);
	xa = WALL / tan(data->beta * RADIANCONV);
	// printf("xa = %d\n", xa);
	while (ft_iswall(data, data->ax, data->ay) == 0)
	{
		data->ax = data->ax + xa;
		data->ay = data->ay + ya;
		//  printf("horiz inter\n");
	}
}

void	ft_vertical(t_data *data)
{
	int ya;
	int	xa;

	
	if (data->beta <= 90 || data->beta >= 270)
		data->bx = (int)(data->posx / WALL) * WALL + 64;
	else
		data->bx = (int)(data->posy / WALL) * WALL - 1;
		// printf("bx = %f\n", data->bx);
	data->by = data->posy + (data->posx - data->bx) * tan(data->beta * RADIANCONV);
	// printf("by = %f\n", data->by); 
	if (data->beta <= 90 || data->beta >= 270)
		xa = WALL;
	else
		xa = -WALL;
	// printf("xa = %d\n", xa);
	ya = WALL * tan(data->beta * RADIANCONV);
	// printf("ya = %d\n", ya);
	while (ft_iswall(data, data->bx, data->by) == 0)
	{
		// printf("basjfhals\n");
		data->bx = data->bx + xa;
		data->by = data->by + ya;
	}

}

void	find_the_wall(t_data *data ,t_env *env)
{
	double	dist1;
	double	dist2;
	double	angle;

	data->beta = data->alpha + 30;
	data->beta = set_degree(data->beta);
	angle = 30;
	printf("beta = %f\n", data->beta);
	data->wallx = 0;
	while (angle != -30)
	{
		// printf("\nhoriz\n");
    	ft_horizontal(data);
		// printf("\nvertic\n");
    	ft_vertical(data);
		// printf("\ndist calc\n");
		dist1 = (int)sqrt(pow(data->posx - data->ax, 2) + (int)pow(data->posy - data->ay, 2));
		dist2 = (int)sqrt(pow(data->posx - data->bx, 2) + (int)pow(data->posy - data->by, 2));
		dist1 = dist1 < dist2 ? dist1 : dist2;
		// printf("\nwall_height\n");
		ft_wall_height(data, dist1, angle);
		draw_wall(data, env);
		// printf("\nincrement\n");
		data->beta -= data->angle_ray;
		data->wallx++;
		angle -= data->angle_ray;
		// printf("\nangleray = %f\nbeta = %f\n",data->angle_ray, data->beta);
	}
}