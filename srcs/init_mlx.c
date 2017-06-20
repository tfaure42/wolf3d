/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   init_mlx->c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tfaure <tfaure@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2017/06/19 13:27:50 by tfaure			#+#	#+#			 */
/*   Updated: 2017/06/20 18:19:34 by tfaure		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		init_mlx(t_env *env)
{
	env->mlx = mlx_init();
	env->img = mlx_new_image(env->mlx, LEN, HEIGHT);
	env->data = mlx_get_data_addr(env->img, &env->bpp, &env->sizeline, &env->endian);
	env->win = mlx_new_window(env->mlx, LEN, HEIGHT, "Wolf3d");
}