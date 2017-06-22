/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 10:53:07 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/22 14:27:47 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int     my_key_func(int keycode, t_env *env)
{
    if (keycode == 53)
        exit(0);
	if (keycode == 126)
	{
		env->dat->px += 0.5;
	}
	if (keycode == 125)
	{
		env->dat->px -= 0.5;
	}
    if (keycode == 124)
    {
		env->dat->alpha -= 3; 
    }
	if (keycode == 123)
    {
		env->dat->alpha += 3;
	}
	mlx_destroy_image(env->mlx, env->img);
	env->img = mlx_new_image(env->mlx, LEN, HEIGHT);
	init_data(env->dat);
	find_the_wall(env->dat, env);
	put_mlx(env);
	return(1);
}