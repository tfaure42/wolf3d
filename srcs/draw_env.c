/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 10:07:46 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/30 17:42:47 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		draw_sky(t_env *env, t_data *data)
{
	int x;
	int y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < LEN)
		{
			env->img_cpy[x + y * LEN] = data->color6;
			x++;
		}
		y++;
	}
}

void		draw_floor(t_env *env, t_data *data)
{
	int x;
	int y;

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
			env->img_cpy[x + y * LEN] = data->color5;
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
