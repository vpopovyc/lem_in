/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_mx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 20:16:18 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/04/15 19:50:27 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_null_it(char **mx, t_uint n)
{
	t_uint		i;

	i = UINT_MAX;
	while (++i != n)
	{
		mx[i] = (char*)malloc(sizeof(char) * (n + 1));
		ft_bzero(mx[i], (size_t)n + 1);
	}
}

t_uint	ft_get_id_from_name(t_room **binds, char *name_to_find)
{
	t_uint	i;

	i = 0;
	if (binds == NO_ROOMS)
		ft_exit("No rooms");
	while (*(binds + i))
	{
		if (ft_strequ((*(binds + i))->name, name_to_find))
			return ((*(binds + i))->id);
		++i;
	}
	ft_exit("Can't find room name that corresponds following link");
	return (0);
}

void	ft_insert_connection_by_ids(char **mx, t_uint id_1, t_uint id_2)
{
	mx[id_1][id_2] = 1;
	mx[id_2][id_1] = 1;
}

void	ft_get_edges(t_root *root, t_acmx *mx, char *line, char *flag)
{
	t_uint		id_1;
	t_uint		id_2;
	char		*name;
	static char	init_flag;

	if (!init_flag)
	{
		mx->acmx = (char**)malloc(sizeof(char*) * (root->n_ofbinds + 1));
		mx->acmx[root->n_ofbinds] = NULL;
		ft_null_it(mx->acmx, root->n_ofbinds);
		init_flag += 1;
		*flag = 0x20;
	}
	name = ft_strndup(line, ft_strclen(line, '-'));
	id_1 = ft_get_id_from_name(root->binds, name);
	ft_strdel(&name);
	name = ft_strdup(ft_strstr(line, "-") + 1);
	id_2 = ft_get_id_from_name(root->binds, name);
	ft_strdel(&name);
	ft_insert_connection_by_ids(mx->acmx, id_1, id_2);
}
