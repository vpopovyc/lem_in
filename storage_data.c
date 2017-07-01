/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:56:14 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/04/15 20:11:48 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_uint		ft_return_elem_cmp(char ***p1, char ***p2, t_uint b)
{
	char	res;

	res = 0;
	if (ft_size_of_pp(*p2) == b)
	{
		ft_ppdel(p1);
		ft_ppdel(p2);
		res = 1;
	}
	else
	{
		ft_ppdel(p1);
		ft_ppdel(p2);
	}
	return ((t_uint)res);
}

static t_uint		ft_elem_cmp(char *sv, char *pv, t_uint i, t_uint j)
{
	char	**p1;
	char	**p2;
	char	b;
	t_uint	t_p1;

	b = 0;
	p1 = ft_strsplit(sv, ' ');
	p2 = ft_strsplit(pv, ' ');
	while (p1[++i] && (j = -1))
	{
		t_p1 = ft_atoi(p1[i]);
		while (p2[++j])
		{
			if (t_p1 == (t_uint)ft_atoi(p2[j]))
			{
				b += 1;
				break ;
			}
		}
	}
	return (ft_return_elem_cmp(&p1, &p2, (t_uint)b));
}

char				**ft_temp_result(t_stack *stack,
	char **old_storage, t_uint size)
{
	char		**new_storage;
	t_uint		i;

	i = UINT_MAX;
	new_storage = (char**)malloc(sizeof(char*) * (size + 1));
	new_storage[size] = NULL;
	while (++i != size && size > 1)
		new_storage[i] = old_storage[i];
	new_storage[size - 1] = ft_stack_to_string(*stack);
	if (size > 1)
		free(old_storage);
	stack_delete(stack);
	return (new_storage);
}

char				**ft_new_storage(char *clean, char **old_storage,
	t_uint *size)
{
	char				**new_storage;
	register t_uint		i;
	t_uint				j;
	t_uint				mal_size;

	i = UINT_MAX;
	j = UINT_MAX;
	mal_size = 0;
	while (++i < *size)
		if (clean[i] == IMPORTANT_PATH)
			++mal_size;
	new_storage = (char**)malloc(sizeof(char*) * mal_size + 1);
	new_storage[mal_size] = NULL;
	i = UINT_MAX;
	while (++i != *size)
	{
		if (clean[i] == IMPORTANT_PATH)
			new_storage[++j] = old_storage[i];
		else
			ft_strdel(&(old_storage[i]));
	}
	*size = j + 1;
	free(old_storage);
	return (new_storage);
}

char				**ft_storage_clean_up(char **old_storage, t_uint *size)
{
	t_uint	i;
	t_uint	j;
	char	clean[*size];

	i = UINT_MAX;
	ft_charzero(clean, *size);
	while (++i < *size && (j = -1))
	{
		while (++j < *size && clean[i] == IMPORTANT_PATH)
		{
			if (i != j && clean[j] == NOT_CLEANED && ft_elem_cmp(old_storage[i],
						old_storage[j], -1, -1))
				clean[j] = TO_BE_CLEANED;
		}
	}
	return (ft_new_storage(clean, old_storage, size));
}
