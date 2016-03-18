/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 14:40:48 by amoinier          #+#    #+#             */
/*   Updated: 2016/03/18 15:45:12 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static	t_point		***ft_realloc(t_point ***p, int nline)
{
	t_point	***tmp;
	int		i;

	i = 0;
	if (!(tmp = (t_point ***)malloc(sizeof(tmp) * (nline + 1))))
		error("error : ft_realloc");
	while (i != nline)
	{
		tmp[i] = p[i];
		i++;
	}
	free(p);
	p = NULL;
	p = tmp;
	return (p);
}

void				verif_map(t_point ***point)
{
	int		x;
	int		y;

	x = 0;
	while (x < point[point[0][0]->sizeline - 1][0]->sizecol)
	{
		if (point[point[0][0]->sizeline - 1][x]->z != 1 &&
		point[point[0][0]->sizeline - 1][x]->z != 9)
			error("error : no wall");
		x++;
	}
	y = 0;
	while (y < point[0][0]->sizeline)
	{
		if (point[y][point[y][0]->sizecol - 1]->z != 1 &&
		point[y][point[y][0]->sizecol - 1]->z != 9)
			error("error : no wall");
		if (point[y][0]->sizecol != point[0][0]->sizecol)
			error("error : not a rectangle");
		y++;
	}
}

t_point				***ft_createstruct(t_env *init, char *av)
{
	t_point	***point;
	int		fd;
	int		i;
	int		ret;
	char	*line;

	i = 0;
	init->name = av;
	if (!(point = (t_point ***)malloc(sizeof(point))))
		error("error : ft_createstruct");
	if ((fd = open(av, O_RDONLY)) == -1)
		error("error : Bad fd");
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		point[i] = init_point(init, line, i);
		point = ft_realloc(point, i + 1);
		free(line);
		i++;
	}
	close(fd);
	if (ret != 0 || i == 0)
		error("error : ret != 0 || i == 0");
	free(line);
	point[0][0]->sizeline = i;
	return (point);
}
