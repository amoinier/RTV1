/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adn.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 11:51:18 by amoinier          #+#    #+#             */
/*   Updated: 2016/03/18 15:47:22 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

double			adn(t_env *init, double xy2[2])
{
	double	size;
	double	dx;
	double	dy;
	double	x;
	double	y;
	double	dist;

	size = fabs(xy2[1]);
	if (fabs(xy2[0]) >= size)
		size = fabs(xy2[0]);
	size *= 300;
	dx = (xy2[0]) / size;
	dy = (xy2[1]) / size;
	x = 0.1;
	y = 0.1;
	while (init->point[(int)y][(int)x] && init->point[(int)y][(int)x]->z != 1 &&
	init->point[(int)y][(int)x]->z != 9)
	{
		x += dx;
		y += dy;
	}
	dist = sqrt(x * x + y * y);
	return (dist);
}
