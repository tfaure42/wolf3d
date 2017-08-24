/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 17:22:09 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/24 19:43:47 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	go_to_night(t_env *env)
{
	if (env->dat->color4 == 0xFF0000)
		set_color_red(env, 1);
	else if (env->dat->color4 == 0xFF8000)
		set_color_orange(env, 1);
	else if (env->dat->color4 == 0x00FFFF)
		set_color_blue_light(env, 1);
	else if (env->dat->color4 == 0x0000FF)
		set_color_blue_dark(env, 1);
	else if (env->dat->color4 == 0x888888)
		set_color_white(env, 1);
	else if (env->dat->color4 == 0xFF00FF)
		set_color_pink(env, 1);
	else if (env->dat->color4 == 0x00FF00)
		set_color_green(env, 1);
	else if (env->dat->color4 == 0x8D6AF7)
		set_color_purple(env, 1);
}

void	set_color_white(t_env *env, int i)
{
	if (i == 0)
	{
		env->dat->color1 = 0xEEEEEE;
		env->dat->color2 = 0xCCCCCC;
		env->dat->color3 = 0xAAAAAA;
		env->dat->color4 = 0x888888;
	}
	else
	{
		env->dat->color1 = 0x808080;
		env->dat->color2 = 0x606060;
		env->dat->color3 = 0x404040;
		env->dat->color4 = 0x202020;
	}
}

void	set_color_pink(t_env *env, int i)
{
	if (i == 0)
	{
		env->dat->color1 = 0xFF99FF;
		env->dat->color2 = 0xFF66FF;
		env->dat->color3 = 0xFF33FF;
		env->dat->color4 = 0xFF00FF;
	}
	else
	{
		env->dat->color1 = 0xCC00CC;
		env->dat->color2 = 0x990099;
		env->dat->color3 = 0x660066;
		env->dat->color4 = 0x330033;
	}
}

void	set_color_green(t_env *env, int i)
{
	if (i == 0)
	{
		env->dat->color1 = 0x99FF99;
		env->dat->color2 = 0x66FF66;
		env->dat->color3 = 0x33FF33;
		env->dat->color4 = 0x00FF00;
	}
	else
	{
		env->dat->color1 = 0x00CC00;
		env->dat->color2 = 0x009900;
		env->dat->color3 = 0x006600;
		env->dat->color4 = 0x003300;
	}
}

void	set_color_purple(t_env *env, int i)
{
	if (i == 0)
	{
		env->dat->color1 = 0xBCA9F5;
		env->dat->color2 = 0xAE95F8;
		env->dat->color3 = 0x9F81F7;
		env->dat->color4 = 0x8D6AF7;
	}
	else
	{
		env->dat->color1 = 0x7F00FF;
		env->dat->color2 = 0x6600CC;
		env->dat->color3 = 0x4C0099;
		env->dat->color4 = 0x330066;
	}
}
