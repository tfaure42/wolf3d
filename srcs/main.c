/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 11:17:29 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/12 11:57:12 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

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
    data.px = 6;
    data.py = 5;
    init_data(&data);
    init_mlx(&env);
    find_the_wall(&data, &env);
    put_mlx(&env);
    mlx_hook(env.win, 2, 3, my_key_func, &env);
	mlx_loop(env.mlx);
    return (MAKE_AMERICA_GREAT_AGAIN);
}