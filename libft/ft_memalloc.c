/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:55:26 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/26 16:56:44 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*memory;
	size_t	i;

	memory = (char *)malloc(size);
	if (!memory)
		return (NULL);
	i = 0;
	while (i < size)
	{
		memory[i] = 0;
		i++;
	}
	return (memory);
}
