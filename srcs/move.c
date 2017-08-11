/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 11:12:38 by myernaux          #+#    #+#             */
/*   Updated: 2017/08/11 11:06:14 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void    move_forward(t_env *env)
{
    env->dat->px += 0.5 * cos(env->dat->alpha * M_PI / 180);
    env->dat->py += 0.5 * sin(env->dat->alpha * M_PI / 180) * -1;
}

void    move_back(t_env *env)
{
    env->dat->px -= 0.5 * cos(env->dat->alpha * M_PI / 180);
    env->dat->py -= 0.5 * sin(env->dat->alpha * M_PI / 180) * -1;
}