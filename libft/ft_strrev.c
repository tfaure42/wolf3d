/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:58:20 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/26 16:57:44 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *str)
{
	int		j;
	int		i;
	char	swap;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
		i++;
	i--;
	j = 0;
	while (i > j)
	{
		swap = str[j];
		str[j] = str[i];
		str[i] = swap;
		i--;
		j++;
	}
	return (str);
}
