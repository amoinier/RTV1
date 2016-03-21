/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 19:09:53 by amoinier          #+#    #+#             */
/*   Updated: 2016/03/21 16:56:49 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static	t_img	*ft_init_img(t_env *init, int w, int h)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(*img))))
		error("error : ft_init_img");
	img->img = mlx_new_image(init->mlx, w, h);
	img->bpp = 0;
	img->sizel = 0;
	img->endn = 0;
	img->cimg = mlx_get_data_addr(img->img, &img->bpp, &img->sizel, &img->endn);
	return (img);
}

static	void	ft_initenv(t_env *init, char *av)
{
	init->width = 1280;
	init->height = 800;
	init->name = av;
	init->nbline = 0;
	init->fig = ft_createstruct(init, av);
}

void			mlx_var(t_env *init, char *av)
{
	init->mlx = mlx_init();
	ft_initenv(init, av);
	init->win = mlx_new_window(init->mlx, 1280, 800,
	"WOLF3D");
	ft_initenv(init, av);
	init->img = ft_init_img(init, init->width, init->height);
	//mlx_hook(init->win, 6, 0, mouse_hook, init);
	//smlx_hook(init->win, 2, 0, key_hook, init);
	//mlx_expose_hook(init->win, expose_hook, init);
	//mlx_loop_hook(init->mlx, loop_hook, init);
	mlx_loop(init->mlx);
}

#include <stdio.h>

int				main(int ac, char **av)
{
	t_env	*init;


	//printf("%f\n", ft_atof("1.69"));
	if (ac == 2)
	{
		if (!(init = (t_env *)malloc(sizeof(*init))))
			error("error : main");
		mlx_var(init, av[1]);
	}
	else
		error("error : ac == 2");
	return (0);
}
