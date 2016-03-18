/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 19:12:54 by amoinier          #+#    #+#             */
/*   Updated: 2016/03/18 17:25:58 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

// int				mouse_hook(int x, int y, t_env *init)
// {
// 	ft_clear_img(init);
// 	mlx_put_image_to_window(init->mlx, init->win, init->img->img, 0, 0);
// 	return (0);
// }

int				key_hook(int keycode, t_env *init)
{
	ft_clear_img(init);
	if (keycode == 53)
	{
		mlx_destroy_image(init->mlx, init->img->img);
		mlx_destroy_window(init->mlx, init->win);
		exit(0);
	}
	mlx_put_image_to_window(init->mlx, init->win, init->img->img, 0, 0);
	return (0);
}

// int				expose_hook(t_env *init)
// {
// 	mlx_put_image_to_window(init->mlx, init->win, init->img->img, 0, 0);
// 	return (0);
// }
//
// int				loop_hook(t_env *init)
// {
// 	init->height *= 1;
// 	return (0);
// }
