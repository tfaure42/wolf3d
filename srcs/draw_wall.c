/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 11:35:18 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/26 16:51:19 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	draw_wall(t_data *data, t_env *env)
{
	int max;
	int y;

	max = HEIGHT - 1;
	y = (HEIGHT / 2) - (data->height / 2);
	data->wally = (max / 2) - (data->height / 2);
	if (data->height > max)
	{
		while (max != -1 && data->wallx < LEN)
		{
			((unsigned int *)env->data)[data->wallx + max * LEN] = data->color;
			max--;
		}
	}
	else if (data->height > 0)
	{
		while (data->wally <= HEIGHT - y && (data->wallx + data->wally * \
		LEN) < LEN * HEIGHT)
		{
			((unsigned int *)env->data)\
			[data->wallx + data->wally * LEN] = data->color;
			data->wally++;
		}
	}
}
