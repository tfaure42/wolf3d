/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 11:17:29 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/30 16:55:58 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		main(int ac, char **av)
{
	t_data	data;
	t_env	env;

	if (ac != 2)
		err_found("wrong arg");
	parse(&data, av[1]);
	env.dat = &data;
	data.alpha = 0;
	data.color1 = 0xBCA9F5;
	data.color2 = 0xAE95F8;
	data.color3 = 0x9F81F7;
	data.color4 = 0x8D6AF7;
	data.color5 = 0x777777;
	data.color6 = 0x58ACFA;
	init_data(&data);
	init_mlx(&env);
	find_the_wall(&data, &env);
	put_mlx(&env, 1);
	mlx_hook(env.win, 2, 0, my_key_func, &env);
	mlx_hook(env.win, 17, 0, mouse_hook_escape, &env);
	mlx_loop(env.mlx);
	return (MAKE_AMERICA_GREAT_AGAIN);
}
