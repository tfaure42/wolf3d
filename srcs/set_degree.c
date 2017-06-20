/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_degree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 09:10:23 by tfaure            #+#    #+#             */
/*   Updated: 2017/06/20 09:31:39 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

double		set_degree(double deg)
{
	if ((deg - 360) > 0)
		deg = deg - 360;
	if (deg < 0)
		deg = deg + 360;
	return (deg);
}