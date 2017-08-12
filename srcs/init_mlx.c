/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 09:07:39 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/12 09:07:41 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/wolf3d.h"

void		init_mlx(t_env *env)
{
	env->mlx = mlx_init();
	env->img = mlx_new_image(env->mlx, LEN, HEIGHT);
	env->data = mlx_get_data_addr(env->img, &env->bpp, &env->sizeline, &env->endian);
	env->win = mlx_new_window(env->mlx, LEN, HEIGHT, "Wolf3d");
}

void		put_mlx(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}