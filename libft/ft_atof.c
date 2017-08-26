/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 19:43:49 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/26 16:56:03 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static float	zero_dot(intmax_t nbr)
{
	int				digits;
	int				diviser;
	intmax_t		tmpnbr;

	digits = 0;
	diviser = 10;
	tmpnbr = nbr;
	while (tmpnbr > 0)
	{
		tmpnbr /= 10;
		digits++;
	}
	while (digits-- > 1)
		diviser *= 10;
	return ((float)nbr / (float)diviser);
}

float			ft_atof(const char *str)
{
	float		res;
	intmax_t	after_comma;
	int			i;
	int			neg;

	neg = 0;
	res = (float)ft_atoi(str);
	if (res == 0 && str[0] == '-')
		neg = 1;
	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (str[i++] == '.')
	{
		after_comma = ft_atoi(str + i);
		res += (res >= 0) ? zero_dot(after_comma) : -zero_dot(after_comma);
	}
	return (neg) ? -res : res;
}
