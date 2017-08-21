/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 11:39:48 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/21 10:47:21 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			init_data(t_data *data)
{
	data->posx = data->px * WALL + (WALL / 2);
	data->posy = data->py * WALL + (WALL / 2);
	data->distpp = ((LEN / 2) / tan((FOV * RADIANCONV) / 2));
	data->angle_ray = FOV / LEN;
	data->alpha = set_degree(data->alpha);
}
