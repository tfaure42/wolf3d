/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 11:12:38 by myernaux          #+#    #+#             */
/*   Updated: 2017/08/10 15:30:14 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void    move_forward(t_env *env)
{
    env->dat->px += cos(env->dat->alpha);
    env->dat->py += sin(env->dat->alpha) * -1;
}

void    move_back(t_env *env)
{
    env->dat->px -= cos(env->dat->alpha);
    env->dat->py -= sin(env->dat->alpha) * -1;
}