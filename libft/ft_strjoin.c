/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:01:56 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/26 16:57:24 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if ((str = (char *)malloc(sizeof(char *) * (len + 1))) == NULL)
			return (NULL);
		ft_strcat(ft_strcpy(str, s1), s2);
		return (str);
	}
	str = NULL;
	return (str);
}
