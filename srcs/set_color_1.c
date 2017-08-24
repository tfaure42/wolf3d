/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 17:24:48 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/24 19:43:33 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	go_to_day(t_env *env)
{
	if (env->dat->color4 == 0x330000)
		set_color_red(env, 0);
	else if (env->dat->color4 == 0x331900)
		set_color_orange(env, 0);
	else if (env->dat->color4 == 0x003333)
		set_color_blue_light(env, 0);
	else if (env->dat->color4 == 0x000033)
		set_color_blue_dark(env, 0);
	else if (env->dat->color4 == 0x202020)
		set_color_white(env, 0);
	else if (env->dat->color4 == 0x330033)
		set_color_pink(env, 0);
	else if (env->dat->color4 == 0x003300)
		set_color_green(env, 0);
	else if (env->dat->color4 == 0x3300660)
		set_color_purple(env, 0);
}

void	set_color_orange(t_env *env, int i)
{
	if (i == 0)
	{
		env->dat->color1 = 0xFFCC99;
		env->dat->color2 = 0xFFB266;
		env->dat->color3 = 0xFF9933;
		env->dat->color4 = 0xFF8000;
	}
	else
	{
		env->dat->color1 = 0xCC6600;
		env->dat->color2 = 0x994C00;
		env->dat->color3 = 0x663300;
		env->dat->color4 = 0x331900;
	}
}

void	set_color_red(t_env *env, int i)
{
	if (i == 0)
	{
		env->dat->color1 = 0xFF9999;
		env->dat->color2 = 0xFF6666;
		env->dat->color3 = 0xFF3333;
		env->dat->color4 = 0xFF0000;
	}
	else
	{
		env->dat->color1 = 0xCC0000;
		env->dat->color2 = 0x990000;
		env->dat->color3 = 0x660000;
		env->dat->color4 = 0x330000;
	}
}

void	set_color_blue_light(t_env *env, int i)
{
	if (i == 0)
	{
		env->dat->color1 = 0xBBFFFF;
		env->dat->color2 = 0x99FFFF;
		env->dat->color3 = 0x66FFFF;
		env->dat->color4 = 0x00FFFF;
	}
	else
	{
		env->dat->color1 = 0x00CCCC;
		env->dat->color2 = 0x009999;
		env->dat->color3 = 0x006666;
		env->dat->color4 = 0x003333;
	}
}

void	set_color_blue_dark(t_env *env, int i)
{
	if (i == 0)
	{
		env->dat->color1 = 0x9999FF;
		env->dat->color2 = 0x6666FF;
		env->dat->color3 = 0x3333FF;
		env->dat->color4 = 0x0000FF;
	}
	else
	{
		env->dat->color1 = 0x0000CC;
		env->dat->color2 = 0x000099;
		env->dat->color3 = 0x000066;
		env->dat->color4 = 0x000033;
	}
}
