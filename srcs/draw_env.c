/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 10:07:46 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/17 13:41:38 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void    draw_sky(t_env *env, t_data *data)
{
    int x;
    int y;
	(void)data;

    y = 0;
    while (y < HEIGHT / 2)
    {
        x = 0;
        while (x < LEN)
        {
            ((unsigned int *)env->data)[x + y * LEN] = data->color6;
            x++;
        }
        y++;
    }
}

void    draw_floor(t_env *env, t_data *data)
{
    int x;
    int y;
	(void)data;

    y = HEIGHT / 2;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < LEN)
        {
            ((unsigned int *)env->data)[x + y * LEN] = data->color5;;
            x++;
        }
        y++;
    }
}

void    draw_env(t_env *env, t_data *data)
{
    draw_sky(env, data);
    draw_floor(env, data);
}
