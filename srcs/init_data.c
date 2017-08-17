/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 11:39:48 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/17 13:38:25 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			init_data(t_data *data)
{
	data->color1 = 0xBCA9F5;
	data->color2 = 0xAE95F8;
	data->color3 = 0x9F81F7;
	data->color4 = 0x8D6AF7;
	data->color5 = 0x777777;
	data->color6 = 0x58ACFA;
	data->posx = data->px * WALL + (WALL / 2);
	data->posy = data->py * WALL + (WALL / 2);
	data->distpp = ((LEN / 2) / tan((FOV * RADIANCONV) / 2));
	data->angle_ray = FOV / LEN;
	data->alpha = set_degree(data->alpha);
}
