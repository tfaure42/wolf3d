/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 11:12:38 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/12 12:45:06 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	move_forward(t_env *env)
{
		env->dat->px += 0.2 * cos(env->dat->alpha * M_PI / 180);
		env->dat->py += (0.2 * sin(env->dat->alpha * M_PI / 180)) * -1;
}

void	move_back(t_env *env)
{
		env->dat->px -= 0.2 * cos(env->dat->alpha * M_PI / 180);
		env->dat->py -= 0.2 * sin(env->dat->alpha * M_PI / 180) * -1;
}

void	move_left(t_env *env)
{
		env->dat->py += 0.2 * cos(env->dat->alpha * M_PI / 180) * -1;
		env->dat->px += (0.2 * sin(env->dat->alpha * M_PI / 180)) * -1;
}

void	move_right(t_env *env)
{
		env->dat->py -= 0.2 * cos(env->dat->alpha * M_PI / 180) * -1;
		env->dat->px -= (0.2 * sin(env->dat->alpha * M_PI / 180)) * -1;
}
