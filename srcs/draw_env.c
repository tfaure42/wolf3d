/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 10:07:46 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/26 10:34:31 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void    draw_sky(t_env *env, t_data *data)
{
    int x;
    int y;

    y = 0;
    while (y < HEIGHT / 2)
    {
        x = 0;
        while (x < LEN)
        {
            ((unsigned int *)env->data)[x + y * LEN] = 0x0058ACFA;
            x++;
        }
        y++;
    }
}

void    draw_floor(t_env *env, t_data *data)
{
    int x;
    int y;

    y = HEIGHT / 2;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < LEN)
        {
            ((unsigned int *)env->data)[x + y * LEN] = 0x0001DF01;
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