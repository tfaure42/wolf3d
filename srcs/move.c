/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 11:12:38 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/26 08:52:49 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void    move_forward(t_env *env)
{
    env->dat->px += 0.5 * cos(env->dat->alpha);
    env->dat->py += 0.5 * -sin(env->dat->alpha);
}

void    move_back(t_env *env)
{
    env->dat->px -= 0.5 * cos(env->dat->alpha);
    env->dat->py -= 0.5 * -sin(env->dat->alpha);
}