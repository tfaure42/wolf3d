/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 21:52:23 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/26 16:57:46 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	int		c;

	i = 0;
	c = 0;
	if (little[0] == '\0')
		return (char*)(big);
	while (big[i] != '\0')
	{
		j = i;
		c = 0;
		while (big[j] == little[c])
		{
			j++;
			c++;
			if (little[c] == '\0')
				return (char*)(&big[i]);
		}
		i++;
	}
	return (NULL);
}
