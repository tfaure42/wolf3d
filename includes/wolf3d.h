/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 11:17:53 by tfaure            #+#    #+#             */
/*   Updated: 2017/06/18 18:15:20 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <mlx.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

# define PLAYER 2

typedef struct  s_data
{
	char	**map;
	int		map_size;
}               t_data;

typedef struct  s_screen
{
    void			*mlx;
	void			*win;
	void			*img;
	int				bpp;
	int				sizeline;
	int				len;
	int				hight;
	int				endian;
	char			*data;
}               t_screen;

int     parse(t_data *data, char *filename);

#endif