/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 11:17:29 by tfaure            #+#    #+#             */
/*   Updated: 2017/06/20 18:19:25 by tfaure           ###   ########.fr       */
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
    while (data.map[i])
    {
		printf("%s\n", data.map[i]);
		i++;
    }
    printf("couco");
    init_data(&data);
    init_mlx(&env);
    find_the_wall(&data, &env);
    return(MAKE_AMERICA_GREAT_AGAIN);
}