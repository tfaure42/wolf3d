/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_day.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 13:40:31 by myernaux          #+#    #+#             */
/*   Updated: 2017/08/17 14:24:12 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	set_color1(t_env *env, int i)
{
	if (i == 0)
	{
		env->dat->color1 = 0xF78181;
		env->dat->color2 = 0xFA5858;
		env->dat->color3 = 0xFE2E2E;
		env->dat->color4 = 0xFF0000;
	}
}
