/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:09:46 by amoinier          #+#    #+#             */
/*   Updated: 2016/03/21 16:53:33 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float	ft_atof(char *s)
{
	int i;
	int	k;
	int	neg;
	float	result;

	i = 0;
	k = 0;
	result = 0;
	neg = 1;
	while (s[i] == 32 || s[i] == '\n' || s[i] == '\r' ||
	s[i] == '\v' || s[i] == '\t' || s[i] == '\f')
		i++;
	if (s[i] == '-')
		neg = -1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			result = result * 10 + s[i] - '0';
		else
			break ;
		i++;
	}
	if (s[i] == '.')
	{
		while (s[i + k])
		{
			if (s[i + k] >= '0' && s[i + k] <= '9')
				result = result * 10 + s[i + k] - '0';
			else
				break ;
			k++;
		}
		result = result / (ft_power(10, k));
	}
	result = result * neg;
	return (result);
}
