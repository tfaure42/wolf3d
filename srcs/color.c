/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 08:05:54 by myernaux          #+#    #+#             */
/*   Updated: 2017/08/21 11:32:31 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	init_color(t_env *env)
{
	color_wall(env);
	color_ground(env);
	color_sky(env);
}

int		mouse_hook_color(int button, int x, int y, t_env *env)
{
	if (button == 1)
	{
		if ((x > 34 && x <= 109) && (y > 34 && y <= 109))
		{
			printf("ok\n");
			set_color1(env, 0);
		}
		else if ((x > 109 && x <= 184) && (y > 34 && y <= 109))
			printf("C2 ok\n");
		else if ((x > 184 && x <= 259) && (y > 34 && y <= 109))
			printf("C3 ok\n");
		else if ((x > 259 && x <= 334) && (y > 34 && y <= 109))
			printf("C4 ok\n");
		else if ((x > 34 && x <= 109) && (y > 109 && y <= 184))
			printf("C5 ok\n");
		else if ((x > 109 && x <= 184) && (y > 109 && y <= 184))
			printf("C6 ok\n");
		else if ((x > 184 && x <= 259) && (y > 109 && y <= 184))
			printf("C7 ok\n");
		else if ((x > 259 && x <= 334) && (y > 109 && y <= 184))
			printf("C8 ok\n");
		else if ((x > 34 && x <= 184) && (y > 257 && y <= 332))
			{
					env->dat->color5 = 0x4C9900;
			}
		else if ((x > 184 && x <= 334) && (y > 257 && y <= 332))
			env->dat->color5 = 0x777777;
		else if ((x > 34 && x <= 184) && (y > 405 && y <= 480))
			env->dat->color6 = 0x58ACFA;
		else if ((x > 184 && x <= 332) && (y > 405 && y <= 480))
			env->dat->color6 = 0x0404B4;
		else if ((x > 0 && x <= 368) && (y > 514 && y <= 589))
			{
				mlx_destroy_image(env->mlx, env->img);
				mlx_destroy_window(env->mlx, env->win2);
				env->img = mlx_new_image(env->mlx, LEN, HEIGHT);
				init_data(env->dat);
				find_the_wall(env->dat, env);
				put_mlx(env, 1);
			}
	}
	return (1);
}

void	color(t_env *env)
{
	env->img2 = mlx_new_image(env->mlx, 368, 589);
	env->data2 = mlx_get_data_addr(env->img2, &env->bpp, &env->sizeline, &env->endian);
	env->win2 = mlx_new_window(env->mlx, 368, 589, "Make your Wolf3d");
	init_color(env);
	put_mlx(env, 2);
	mlx_hook(env->win2, 4, 3, mouse_hook_color, env);
	mlx_loop(env->mlx);
}
