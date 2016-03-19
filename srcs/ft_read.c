/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 14:40:48 by amoinier          #+#    #+#             */
/*   Updated: 2016/03/19 19:46:08 by amoinier         ###   ########.fr       */
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

int			count(char **str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[j])
	{
		if (ft_strstr(str[j], "object"))
			i++;
		j++;
	}
	return (i);
}

float		ft_search(char *s, char *sch)
{
	int	i;

	i = (ft_strlen(s) - ft_strlen(ft_strstr(s, sch))) + ft_strlen(sch) + 1;
	return (1);
}

void		edit_fig(t_fig **fig, char	**str)
{
	int	i;
	int	j;

	i = 0;
	while (i < count(str))
	{
		j = 0;
		while (str[j])
		{
			if (ft_strstr(str[j], "object"))
				fig[j]->obj = ft_search(str[j], "object");
			j++;
		}
	}
}

t_fig	**ft_createstruct(t_env *init, char *av)
{
	t_fig	**fig;
	char	*line;
	char	**str;
	int		i;
	int		fd;
	int		ret;

	i = 0;
	if ((fd = open(av, O_RDONLY)))
		error("error : bad fd");
	str = NULL;
	while ((ret = get_next_line(fd, &line)))
	{
		ft_dstrcpy(str, i, line);
		i++;
	}
	if (!(fig = ((t_fig **)malloc(sizeof(fig) * (count(str) + 1)))))
		error("error : malloc fig");
	init->height *= 1;
	edit_fig(fig, str);
	return (fig);
}
