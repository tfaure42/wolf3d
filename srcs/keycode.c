/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 10:53:07 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/26 16:22:20 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		mouse_hook_escape(t_env *env)
{
	if (env)
		exit(0);
	return (1);
}

int		my_key_func(int keycode, t_env *env)
{
	if (keycode == 24)
		color(env);
	if (keycode == 53)
		exit(0);
	if (keycode == 13)
		move_forward(env);
	if (keycode == 1)
		move_back(env);
	if (keycode == 0)
		move_left(env);
	if (keycode == 2)
		move_right(env);
	if (keycode == 124)
		env->dat->alpha -= 2;
	if (keycode == 123)
		env->dat->alpha += 2;
	reset_img(env->data, LEN - 1, HEIGHT - 1);
	init_data(env->dat);
	find_the_wall(env->dat, env);
	put_mlx(env, 1);
	return (1);
}
