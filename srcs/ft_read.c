/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex <Alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 14:40:48 by amoinier          #+#    #+#             */
/*   Updated: 2016/03/28 09:55:57 by Alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

char	**ft_dstrcpy(char **str, int i, char *line)
{
	char	**str2;
	int	x;

	x = 0;
	if (!(str2 = (char **)malloc(sizeof(str2) * (i + 1))))
		return (NULL);
	while (x < i)
	{
		str2[x] = ft_strdup(str[x]);
		x++;
	}
	str2[x] = ft_strdup(line);
	return (str2);
}

int			count(char **str, int i)
{
	int	k;
	int	j;

	j = 0;
	k = 0;
	while (j < i)
	{
		if (ft_strstr(str[j], "object"))
			k++;
		j++;
	}
	return (k);
}

int		ft_search(char *s, char *sch)
{
	int	i;

	i = (ft_strlen(s) - ft_strlen(ft_strstr(s, sch))) + ft_strlen(sch) + 1;
	return (i);
}

t_fig		*init_fig(void)
{
	t_fig	*fig;

	if (!(fig = (t_fig *)malloc(sizeof(*fig))))
		error("error malloc elem fig");
	fig->obj = NULL;
	fig->ray = 0;
	fig->posx = 0;
	fig->posy = 0;
	fig->posz = 0;
	fig->color = 0;
	return (fig);
}

void		edit_fig(t_env *init, t_fig **fig, char	**str)
{
	int	i;
	int	j;

	i = 0;
	while (i < count(str, init->nbline))
	{
		fig[i] = init_fig();
		j = 0;
		while (j < init->nbline)
		{
			if (!init->name && ft_strstr(str[j], "name"))
				init->name = ft_strdup(&str[j][ft_search(str[j], "name")]);
			else if (ft_strstr(str[j], "camx"))
				init->camx = ft_atof(&str[j][ft_search(str[j], "camx")]);
			else if (ft_strstr(str[j], "camy"))
				init->camy = ft_atof(&str[j][ft_search(str[j], "camy")]);
			else if (ft_strstr(str[j], "camz"))
				init->camz = ft_atof(&str[j][ft_search(str[j], "camz")]);
			else if (ft_strstr(str[j], "fenx"))
				init->width = ft_atoi(&str[j][ft_search(str[j], "fenx")]);
			else if (ft_strstr(str[j], "feny"))
				init->height = ft_atoi(&str[j][ft_search(str[j], "feny")]);
			else if (!fig[i]->obj && ft_strstr(str[j], "object"))
				fig[i]->obj = ft_strdup(&str[j][ft_search(str[j], "object")]);
			else if (!fig[i]->posx && ft_strstr(str[j], "posx"))
				fig[i]->posx = ft_atof(&str[j][ft_search(str[j], "posx")]);
			else if (!fig[i]->posy && ft_strstr(str[j], "posy"))
				fig[i]->posy = ft_atof(&str[j][ft_search(str[j], "posy")]);
			else if (!fig[i]->posz && ft_strstr(str[j], "posz"))
				fig[i]->posz = ft_atof(&str[j][ft_search(str[j], "posz")]);
			else if (!fig[i]->ray && ft_strstr(str[j], "ray"))
				fig[i]->ray = ft_atof(&str[j][ft_search(str[j], "ray")]);
			else if (!fig[i]->obj && ft_strstr(str[j], "color"))
				fig[i]->color = ft_atoi(&str[j][ft_search(str[j], "color")]);
			j++;
		}
		i++;
	}
}

#include <stdio.h>

t_fig	**ft_createstruct(t_env *init, char *av)
{
	t_fig	**fig;
	char	*line;
	char	**str;
	int		i;
	int		fd;
	int		ret;

	i = 0;
	if ((fd = open(av, O_RDONLY)) == -1)
		error("error : bad fd");
	if (!(str = (char **)malloc(sizeof(str))))
		error("error : malloc str");
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		str = ft_dstrcpy(str, i, line);
		i++;
	}
	init->nbline = i;
	if (!(fig = ((t_fig **)malloc(sizeof(fig) * (count(str, init->nbline) + 1)))))
		error("error : malloc fig");
	edit_fig(init, fig, str);
	printf("%f\n", init->camy);
	return (fig);
}
