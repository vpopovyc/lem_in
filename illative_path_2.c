/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illative_path_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:26:29 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/04/15 19:54:32 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_swap(char **sv, char **pv)
{
	char *tmp;

	tmp = *sv;
	*sv = *pv;
	*pv = tmp;
}

static t_uint	ft_check_lmns_on_path(t_path **set,
	char **sdpath, t_uint lmn_n)
{
	t_uint	i;
	t_uint	n_of_path;
	t_uint	id;

	i = UINT_MAX;
	n_of_path = 0;
	while (sdpath[++i])
	{
		id = ft_atoi(sdpath[i]);
		id = set[id]->lenght;
		if (lmn_n > id)
		{
			++n_of_path;
			--lmn_n;
		}
	}
	ft_ppdel(&sdpath);
	return (n_of_path);
}

static void		ft_s_init(t_sort *s, t_uint size)
{
	s->tmp = 0;
	s->i = UINT_MAX;
	s->ans = 0;
	s->num_of_pos = 0;
	s->size = size;
}

char			**ft_sort(char *sv, t_path **set, char ***free)
{
	char	**pv;
	t_uint	i;
	t_uint	j;
	t_uint	id_1;
	t_uint	id_2;

	i = 0;
	pv = ft_strsplit(sv, ' ');
	if (free)
		*free = pv;
	while (pv[i])
	{
		j = UINT_MAX;
		while (pv[++j])
		{
			id_2 = ft_atoi(pv[j]);
			id_2 = set[id_2]->lenght;
			id_1 = ft_atoi(pv[i]);
			id_1 = set[id_1]->lenght;
			if (id_1 < id_2)
				ft_swap(&pv[i], &pv[j]);
		}
		++i;
	}
	return (pv);
}

t_path			**ft_sort_and_decide(t_path **set,
		char **path, char *mark, t_uint *ar)
{
	t_sort	s;

	ft_s_init(&s, ar[1]);
	while (++s.i < s.size)
	{
		if (mark[s.i] != BAD_MARK)
		{
			s.tmp = ft_check_lmns_on_path(set,
					ft_sort(path[(int)mark[s.i]], set, &(s.free)), ar[0]);
			if (s.tmp > s.num_of_pos)
			{
				s.ans = mark[s.i];
				s.num_of_pos = s.tmp;
			}
		}
	}
	if (s.num_of_pos == 0)
		return (ft_find_shortest_path(mark, set, path, ar));
	return (ft_ret_opt_path(ft_sort(path[(int)s.ans], set, NULL), set, ar));
}
