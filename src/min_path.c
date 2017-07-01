/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 21:21:52 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/04/15 19:56:34 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path				**ft_ret_opt_path(char **sv, t_path **set, t_uint *size)
{
	t_path	**ret;
	t_uint	i;
	t_uint	sv_size;

	i = UINT_MAX;
	sv_size = ft_size_of_pp(sv);
	ret = (t_path**)malloc(sizeof(t_path*) * (sv_size + 1));
	ret[sv_size] = NULL;
	while (++i != sv_size)
		ret[i] = set[ft_atoi(sv[i])];
	ft_ppdel(&sv);
	free(size);
	return (ret);
}

static t_uint		ft_minpath_lenght(char *path, t_path **set)
{
	char	**sv;
	t_uint	res;
	t_uint	i;
	t_uint	id;

	i = UINT_MAX;
	res = 0;
	sv = ft_strsplit(path, ' ');
	while (sv[++i])
	{
		id = ft_atoi(sv[i]);
		if (res == FIRST_INIT || res > set[id]->lenght)
			res = set[id]->lenght;
	}
	ft_ppdel(&sv);
	return (res);
}

t_path				**ft_find_shortest_path(char *mark,
		t_path **set, char **path, t_uint *size)
{
	t_uint	i;
	t_uint	t_i;
	t_uint	res;
	t_uint	nd;

	res = 0;
	t_i = 0xffff;
	i = UINT_MAX;
	while (++i < size[1] + 1)
	{
		if (mark[i] != BAD_MARK)
		{
			nd = ft_minpath_lenght(path[(int)mark[i]], set);
			if (nd < t_i)
			{
				res = mark[i];
				t_i = nd;
			}
		}
	}
	return (ft_ret_opt_path(ft_sort(path[res], set, NULL), set, size));
}
