/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_to_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:13:46 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/26 16:56:01 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fl_to_int(float fl)
{
	int new;
	int tmp;
	int tmp2;

	tmp = fl;
	tmp2 = fl - 0.5;
	if (tmp == tmp2)
		return ((new = fl) + 1);
	else
		return (new = fl);
}
