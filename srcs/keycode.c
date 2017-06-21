/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 10:53:07 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/21 16:49:07 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int     my_key_func(int keycode, t_env *env)
{
    if (keycode == 53)
        exit(0);
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