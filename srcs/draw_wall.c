/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 11:35:18 by tfaure            #+#    #+#             */
/*   Updated: 2017/06/21 15:10:19 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void    draw_wall(t_data *data, t_env *env)
{
    int max;
    int y;

    max = HEIGHT - 1;
    y = (HEIGHT / 2) - (data->height / 2);
    data->wally = (HEIGHT / 2) - (data->height / 2);
    if (data->height >= max)
    {
        while (max != 0)
        {
            ((unsigned int *)env->data)[data->wallx + max * LEN] = 0xFF0000;
            max--;
        }
    }
    else
    {
        while (data->wally <= HEIGHT - y)
        {
            ((unsigned int *)env->data)[data->wallx + data->wally * LEN] = 0xFF0000;
            data->wally++;
        }
    }
}