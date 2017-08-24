/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 09:28:55 by myernaux          #+#    #+#             */
/*   Updated: 2017/08/24 18:35:11 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	ft_square(t_env *env, int px, int py, int color)
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
	if (n == 0)
		return (0xFF0000);
	else if (n == 1)
		return (0xFE9A2E);
	else if (n == 2)
		return (0x00BFFF);
	else if (n == 3)
		return (0x0040FF);
	else if (n == 4)
		return (0xFFFFFF);
	else if (n == 5)
		return (0xFF00BF);
	else if (n == 6)
		return (0x3ADF00);
	else if (n == 7)
		return (0x8D6AF7);
	return (0);
}

void		color_wall(t_env *env)
{
	int x;
	int y;
	int n;
	int color;

	(void)env;
	n = 0;
	y = 34;
	while (y <= 184)
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
