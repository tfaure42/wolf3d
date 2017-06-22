/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 11:39:48 by tfaure            #+#    #+#             */
/*   Updated: 2017/06/22 12:10:33 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			init_data(t_data *data)
{
	// printf("init_data\n");
	data->posx = PLACEPLAYERX * WALL + (WALL / 2);
	data->posy = PLACEPLAYERY * WALL + (WALL / 2);
	// printf("posx = %f, posy = %f\n", data->posx, data->posy);
	data->distpp = ((LEN / 2) / tan((FOV * RADIANCONV) / 2));
	data->angle_ray = FOV / LEN;
	printf("%f",data->angle_ray);
	// data->alpha = set_degree(data->alpha);
	// printf("distpp = %d, alpha = %f\n", data->distpp, data->alpha);
}