/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 20:41:50 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/26 16:56:07 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int c)
{
	int	mincl;
	int maxcl;
	int	min;
	int max;

	min = 'a';
	max = 'z';
	mincl = 'A';
	maxcl = 'Z';
	if ((c >= min && c <= max) || (c >= mincl && c <= maxcl))
		return (1);
	else
		return (0);
}
