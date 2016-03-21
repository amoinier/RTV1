/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 14:40:48 by amoinier          #+#    #+#             */
/*   Updated: 2016/03/21 17:56:35 by amoinier         ###   ########.fr       */
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
		while (str[j])
		{
			ft_strstr(str[j], "name");
			//init->name = ft_strdup(&str[j][ft_search(str[j], "name")]);
			j++;
		}
		i++;
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
	return (fig);
}
