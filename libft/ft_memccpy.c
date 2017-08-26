/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:20:39 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/26 16:56:45 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*buf;
	unsigned char	*buf2;
	size_t			i;
	unsigned char	x;

	buf = (unsigned char *)dst;
	buf2 = (unsigned char *)src;
	x = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if ((*buf++ = *buf2++) == x)
			return (buf);
		i++;
	}
	return (NULL);
}
