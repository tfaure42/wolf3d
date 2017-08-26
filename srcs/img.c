/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 11:47:45 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/26 16:51:31 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	reset_img(char *data, int x_max, int y_max)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (y < y_max)
	{
		while (x < x_max)
		{
			((unsigned int *)data)[y * x_max + x] = 0;
			x++;
		}
		x = 0;
		y++;
	}
}
