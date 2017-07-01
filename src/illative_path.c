/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illative_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:02:38 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/04/15 19:55:14 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_charff(char ar[], t_uint n)
{
	t_uint	i;

	i = 0;
	while (i < n)
	{
		ar[i] = -1;
		i++;
	}
}

static t_uint	ft_maxpath_lenght(char *path, t_path **set)
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
		if (res == FIRST_INIT || res < set[id]->lenght)
			res = set[id]->lenght;
	}
	ft_ppdel(&sv);
	return (res);
}

static t_uint	ft_id(char *path)
{
	char	**sv;
	t_uint	res;

	sv = ft_strsplit(path, ' ');
	res = ft_size_of_pp(sv);
	ft_ppdel(&sv);
	return (res);
}

static t_uint	*ft_arr(t_uint n1, t_uint n2)
{
	t_uint	*ar;

	ar = (t_uint*)malloc(sizeof(t_uint) * 3);
	ar[0] = n1;
	ar[1] = n2;
	ar[2] = 0;
	return (ar);
}

t_path			**ft_illative_path(char **path, t_uint lmn_n,
	t_path **set, t_uint size)
{
	char	mark[size];
	char	lenght[size];
	t_uint	i;
	t_uint	path_lenght;
	t_uint	id;

	i = UINT_MAX;
	ft_charff(mark, size);
	ft_charzero(lenght, size);
	while (++i < size)
	{
		id = ft_id(path[i]);
		path_lenght = ft_maxpath_lenght(path[i], set);
		if ((path_lenght < (t_uint)lenght[id]) || lenght[id] == NO_SIZE)
		{
			mark[id] = (char)i;
			lenght[id] = (char)path_lenght;
		}
	}
	return (ft_sort_and_decide(set, path, mark, ft_arr(lmn_n, size)));
}
