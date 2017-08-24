/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 11:12:38 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/24 13:33:36 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	move_forward(t_env *env)
{
	double tmpx;
	double tmpy;

	tmpx = env->dat->px + 0.4 * cos(env->dat->alpha * M_PI / 180);
	tmpy = env->dat->py + 0.4 * sin(env->dat->alpha * M_PI / 180) * -1;
	if (env->dat->map[fl_to_int(tmpx)][fl_to_int(tmpy)] != '1'
		&& (tmpx) >= 0.5 && (tmpy) >= 0.5 && (tmpx)
				<= env->dat->map_size - 1 && (tmpy) <= env->dat->map_size - 1)
	{
		env->dat->px += 0.3 * cos(env->dat->alpha * M_PI / 180);
		env->dat->py += (0.3 * sin(env->dat->alpha * M_PI / 180)) * -1;
	}
	printf("%f = x %f = y\n", env->dat->px, env->dat->py);
}

void	move_back(t_env *env)
{
	double tmpx;
	double tmpy;

	tmpx = env->dat->px - 0.4 * cos(env->dat->alpha * M_PI / 180);
	tmpy = env->dat->py - (0.4 * sin(env->dat->alpha * M_PI / 180)) * -1; 
	if (env->dat->map[fl_to_int(tmpx)][fl_to_int(tmpy)] != '1'
		&& (tmpx) >= 0.5 && (tmpy) >= 0.5 && (tmpx)
				<= env->dat->map_size - 1 && (tmpy) <= env->dat->map_size - 1)
	{
		env->dat->px -= 0.3 * cos(env->dat->alpha * M_PI / 180);
		env->dat->py -= 0.3 * sin(env->dat->alpha * M_PI / 180) * -1;
	}
	printf("%f = x %f = y\n", env->dat->px, env->dat->py);
}

void	move_left(t_env *env)
{
	double tmpx;
	double tmpy;

	tmpy = env->dat->py + 0.4 * cos(env->dat->alpha * M_PI / 180) * -1;
	tmpx = env->dat->px + (0.4 * sin(env->dat->alpha * M_PI / 180)) * -1;
	if (env->dat->map[fl_to_int(tmpx)][fl_to_int(tmpy)] != '1'
		&& (tmpx) >= 0.5 && (tmpy) >= 0.5 && (tmpx)
				<= env->dat->map_size - 1 && (tmpy) <= env->dat->map_size - 1)
	{
		env->dat->px += (0.3 * sin(env->dat->alpha * M_PI / 180)) * -1;
		env->dat->py += 0.3 * cos(env->dat->alpha * M_PI / 180) * -1;
	}
	printf("%f = x %f = y\n", env->dat->px, env->dat->py);
}

void	move_right(t_env *env)
{
	double tmpx;
	double tmpy;

	tmpy = env->dat->py - 0.4 * cos(env->dat->alpha * M_PI / 180) * -1;
	tmpx = env->dat->px - (0.4 * sin(env->dat->alpha * M_PI / 180)) * -1;
	if (env->dat->map[fl_to_int(tmpx)][fl_to_int(tmpy)] != '1'
		&& (tmpx) >= 0.5 && (tmpy) >= 0.5 && (tmpx)
				<= env->dat->map_size - 1 && (tmpy) <= env->dat->map_size - 1)
	{
		env->dat->px -= (0.3 * sin(env->dat->alpha * M_PI / 180)) * -1;
		env->dat->py -= 0.3 * cos(env->dat->alpha * M_PI / 180) * -1;
	}
	printf("%f = x %f = y\n", env->dat->px, env->dat->py);
}
