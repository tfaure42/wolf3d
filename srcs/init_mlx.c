/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 09:07:39 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/30 17:41:11 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		init_mlx(t_env *env)
{
	env->mlx = mlx_init();
	if (!(env->img_cpy = (unsigned int *)malloc(sizeof(unsigned int) *
					((LEN * HEIGHT)))))
		err_found("malloc error");
	if (SS == 1)
	{
		env->img = mlx_new_image(env->mlx, LEN / 2, HEIGHT / 2);
		env->data = mlx_get_data_addr(env->img, &env->bpp, &env->sizeline, \
		&env->endian);
		env->win = mlx_new_window(env->mlx, LEN / 2, HEIGHT / 2, "Wolf3d_SS");
	}
	else
	{
		env->img = mlx_new_image(env->mlx, LEN, HEIGHT);
		env->data = mlx_get_data_addr(env->img, &env->bpp, &env->sizeline, \
		&env->endian);
		env->win = mlx_new_window(env->mlx, LEN, HEIGHT, "Wolf3d");
	}
}

void		put_mlx(t_env *env, int i)
{
	if (i == 1)
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	if (i == 2)
		mlx_put_image_to_window(env->mlx, env->win2, env->img2, 0, 0);
}
