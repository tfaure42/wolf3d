/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_splited_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 13:44:18 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/26 16:56:02 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		free_splited_str(char **str)
{
	int i;

	i = 0;
	while (str[i])
		ft_memdel((void **)&str[i++]);
	ft_memdel((void **)&str);
}
