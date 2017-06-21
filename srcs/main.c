/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 11:17:29 by tfaure            #+#    #+#             */
/*   Updated: 2017/06/21 11:43:46 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
/*
int				my_key_func(int keycode, t_screen *fst)
{
	choose_action(keycode, fst);
	mlx_destroy_image(fst->mlx, fst->img);
	fst->img = mlx_new_image(fst->mlx, fst->len, fst->hight);
	ft_put_pix(fst->fp, fst, NULL, NULL);
	mlx_put_image_to_window(fst->mlx, fst->win, fst->img, 0, 0);
	return (1);
}
*/
int     main(int ac,char **av)
{
    t_data  data;
    t_env   env;
    int     i;

    i = 0;    
    if (ac != 2)
        err_found("wrong arg");
    parse(&data, av[1]);
	env.dat = &data;
    data.alpha = 0;
    while (data.map[i])
    {
		printf("%s\n", data.map[i]);
		i++;
    }
    init_data(&data);
    init_mlx(&env);
    find_the_wall(&data, &env);
    put_mlx(&env);
    mlx_hook(env.win, 2, 3, my_key_func, &env);
	mlx_loop(env.mlx);
    return(MAKE_AMERICA_GREAT_AGAIN);
}