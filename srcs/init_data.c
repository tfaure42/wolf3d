/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 11:39:48 by tfaure            #+#    #+#             */
/*   Updated: 2017/06/20 09:42:56 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		find_player_position(t_data *data)
{
	int     x;
	int     y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == '2')
			{
				data->posy = x * WALL + (WALL / 2);
				data->posx = y * WALL + (WALL / 2);
			}
			y++;
		}
		x++;
	}
}

void			init_data(t_data *data)
{
	find_player_position(data);
	// printf("posx = %f, posy = %f\n", data->posx, data->posy);
	data->distpp = ((LEN / 2) / tan((FOV * RADIANCONV) / 2));
	data->angle_ray = 0.1875;
	printf("%f",data->angle_ray);
	data->alpha = 60;
	data->alpha = set_degree(data->alpha);
	printf("distpp = %d, alpha = %f\n", data->distpp, data->alpha);
}