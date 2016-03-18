/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createstruct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 09:42:35 by amoinier          #+#    #+#             */
/*   Updated: 2016/03/18 15:48:15 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static	t_point		*ft_pointnew(int x, int y, int z, int coln)
{
	t_point	*point;

	if (!(point = (t_point *)malloc(sizeof(*point))))
		error("error : ft_pointnew");
	point->x = x;
	point->y = y;
	point->z = z;
	point->sizeline = 0;
	if (x == 0)
	{
		point->sizecol = coln;
		if (z != 1 && z != 9)
			error("error : no wall");
	}
	if (y == 0)
	{
		if (z != 1 && z != 9)
			error("error : no wall");
	}
	return (point);
}

static	int			verif_str(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < 48 || s[i] > 57)
		{
			ft_putendl(s);
			ft_putchar(s[i]);
			ft_putchar('\n');
			ft_putnbr(i);
			ft_putchar('\n');
			error("error : verif_str");
		}
		i++;
	}
	return (1);
}

t_point				**init_point(t_env *init, char *line, int j)
{
	int		i;
	int		coln;
	char	**s;
	t_point	**point;

	i = 0;
	coln = ft_countcara(line);
	s = ft_strsplit(line, 32);
	if (!(point = (t_point **)malloc(sizeof(*point) * (coln + 1))))
		error("error : init_point");
	while (i < coln)
	{
		verif_str(s[i]);
		point[i] = ft_pointnew(i, j, ft_atoi(s[i]), coln);
		free(s[i]);
		i++;
	}
	if (i == 0)
		error("error : i == 0");
	free(s);
	init->height *= 1;
	return (point);
}
