/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 10:07:46 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/24 18:38:30 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		draw_sky(t_env *env, t_data *data)
{
	int x;
	int y;

	(void)data;
	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < LEN)
		{
			((unsigned int *)env->data)[x + y * LEN] = data->color6;
			x++;
		}
		y++;
	}
}

void		draw_floor(t_env *env, t_data *data)
{
	int x;
	int y;

	(void)data;
	if (env->dat->color5 == 0x333333)
		env->dat->color5 = 0x777777;
	if (env->dat->color5 == 0x003300)
		env->dat->color5 = 0x4C9900;
	if (env->dat->color6 == 0x000055 && env->dat->color5 == 0x4C9900)
		env->dat->color5 = 0x003300;
	else if (env->dat->color6 == 0x000055 && env->dat->color5 == 0x777777)
		env->dat->color5 = 0x333333;
	y = HEIGHT / 2;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < LEN)
		{
			((unsigned int *)env->data)[x + y * LEN] = data->color5;
			x++;
		}
		y++;
	}
}

void		draw_env(t_env *env, t_data *data)
{
	draw_sky(env, data);
	draw_floor(env, data);
}
