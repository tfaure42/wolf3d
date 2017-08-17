/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_sky.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 09:42:30 by myernaux          #+#    #+#             */
/*   Updated: 2017/08/17 10:31:58 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		ft_square(t_env *env, int px, int py, int color)
{
	int x;
	int y;

	y = -1;
	while (y++ < 75)
	{
		x = -1;
		while (x++ < 75)
		{
			if (env->data2 != NULL)
				((unsigned int *)env->data2)[(px + x) + (py + y) * 368] = color;
		}
	}
}

static int	set_color(t_env *env, int n)
{
	(void)env;

	if (n == 0 || n == 1)
		return (0x58ACFA);
	else if (n == 2 || n == 3)
		return (0x0404B4);
	return (0);
}

void	color_sky(t_env *env)
{
	int x;
	int y;
	int n;
	int color;
	(void)env;

	n = 0;
	y = 405;
	while (y <= 405)
	{
		x = 34;
		while (x <= 259)
		{
			color = set_color(env, n);
			ft_square(env, x, y, color);
			x += 75;
			n++;
		}
		y += 75;
	}
}
