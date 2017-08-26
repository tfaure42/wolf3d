/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 22:44:50 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/26 16:57:41 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	while (*s)
		s++;
	if (c == '\0')
		return ((char*)s);
	s--;
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s--;
	}
	return (NULL);
}
