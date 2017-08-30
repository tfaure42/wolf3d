/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing_wolf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 17:32:35 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/08/30 17:50:12 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	anti_aliasing_on(t_env *e, unsigned int *img_temp)
{
	int x;
	int y;
	int x1;
	int y1;

	y = 0;
	y1 = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		x1 = 0;
		while (x < LEN / 2)
		{
			((unsigned int *)e->data)[x + y * LEN / 2] = AVERAGE(AVERAGE(\
					img_temp[x1 + y1 * LEN], img_temp[(x1 + 1) + (y1 * LEN)]),\
					AVERAGE(img_temp[x1 + (y1 + 1) * LEN], \
						img_temp[(x1 + 1) + (y1 + 1) * LEN]));
			x1 += 2;
			x++;
		}
		y++;
		y1 += 2;
	}
}

void	anti_aliasing_wolf(t_env *e, unsigned int *img_temp)
{
	int x;
	int y;

	y = 0;
	if (SS)
	{
		anti_aliasing_on(e, e->img_cpy);
		return ;
	}
	while (y < HEIGHT)
	{
		x = 0;
		while (x < LEN)
		{
			((unsigned int *)e->data)[x + y * LEN] = img_temp[x + y * LEN];
			x++;
		}
		y++;
	}
}
