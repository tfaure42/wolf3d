/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 11:12:38 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/26 16:37:06 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	move_forward(t_env *env)
{
	float tmpx;
	float tmpy;

	tmpx = env->dat->px + 0.2 * cos(env->dat->alpha * M_PI / 180);
	tmpy = env->dat->py + 0.2 * sin(env->dat->alpha * M_PI / 180) * -1;
	if (env->dat->map[fl_to_int(tmpx)][fl_to_int(tmpy)] != '1'
		&& (tmpx) >= 0.5 && (tmpy) >= 0.5 && (tmpx)
				<= env->dat->map_size - 1.5 && (tmpy) <= env->dat->map_size \
				- 1.5)
	{
		env->dat->px += 0.1 * cos(env->dat->alpha * M_PI / 180);
		env->dat->py += (0.1 * sin(env->dat->alpha * M_PI / 180)) * -1;
	}
}

void	move_back(t_env *env)
{
	float tmpx;
	float tmpy;

	tmpx = env->dat->px - 0.2 * cos(env->dat->alpha * M_PI / 180);
	tmpy = env->dat->py - (0.2 * sin(env->dat->alpha * M_PI / 180)) * -1;
	if (env->dat->map[fl_to_int(tmpx)][fl_to_int(tmpy)] != '1'
		&& (tmpx) >= 0.5 && (tmpy) >= 0.5 && (tmpx)
			<= env->dat->map_size - 1.5 && (tmpy) <= env->dat->map_size - 1.5)
	{
		env->dat->px -= 0.1 * cos(env->dat->alpha * M_PI / 180);
		env->dat->py -= 0.1 * sin(env->dat->alpha * M_PI / 180) * -1;
	}
}

void	move_left(t_env *env)
{
	float tmpx;
	float tmpy;

	tmpy = env->dat->py + 0.2 * cos(env->dat->alpha * M_PI / 180) * -1;
	tmpx = env->dat->px + (0.2 * sin(env->dat->alpha * M_PI / 180)) * -1;
	if (env->dat->map[fl_to_int(tmpx)][fl_to_int(tmpy)] != '1'
		&& (tmpx) >= 0.5 && (tmpy) >= 0.5 && (tmpx)
			<= env->dat->map_size - 1.5 && (tmpy) <= env->dat->map_size - 1.5)
	{
		env->dat->px += (0.1 * sin(env->dat->alpha * M_PI / 180)) * -1;
		env->dat->py += 0.1 * cos(env->dat->alpha * M_PI / 180) * -1;
	}
}

void	move_right(t_env *env)
{
	float tmpx;
	float tmpy;

	tmpy = env->dat->py - 0.2 * cos(env->dat->alpha * M_PI / 180) * -1;
	tmpx = env->dat->px - (0.2 * sin(env->dat->alpha * M_PI / 180)) * -1;
	if (env->dat->map[fl_to_int(tmpx)][fl_to_int(tmpy)] != '1'
		&& (tmpx) >= 0.5 && (tmpy) >= 0.5 && (tmpx)
			<= env->dat->map_size - 1.5 && (tmpy) <= env->dat->map_size - 1.5)
	{
		env->dat->px -= (0.1 * sin(env->dat->alpha * M_PI / 180)) * -1;
		env->dat->py -= 0.1 * cos(env->dat->alpha * M_PI / 180) * -1;
	}
}
