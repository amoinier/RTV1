/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 19:10:31 by amoinier          #+#    #+#             */
/*   Updated: 2016/03/18 15:45:36 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libft.h"
# include <mlx.h>

# define RAD 0.0174532925
# define PI 3.14159265359

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			sizeline;
	int			sizecol;
}				t_point;

typedef	struct	s_img
{
	void		*img;
	char		*cimg;
	int			bpp;
	int			sizel;
	int			endn;
}				t_img;

typedef	struct	s_env
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;

	char		*name;

	t_img		*img;
	t_point		***point;
}				t_env;

int				mouse_hook(int x, int y, t_env *init);
int				key_hook(int keycode, t_env *init);
int				loop_hook(t_env *init);
int				expose_hook(t_env *init);

void			mlx_var(t_env *init, char *av);

double			adn(t_env *init, double xy2[2]);

void			pixel_put_image(t_env *init, int x, int y, int color);
void			ft_clear_img(t_env *init);

int				ft_countcara(char *str);
t_point			***ft_createstruct(t_env *init, char *av);
t_point			**init_point(t_env *init, char *line, int j);
void			verif_map(t_point ***point);

int				error(char *s);

#endif
