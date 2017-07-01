/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_data_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 15:01:28 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/04/11 15:01:41 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_uint	ft_path_cmp(t_path *path1, t_path *path2, t_uint i, t_uint j)
{
	char	**p1;
	char	**p2;
	char	b;
	int		t_p1;

	b = 0;
	p1 = ft_strsplit(path1->path, ' ');
	p2 = ft_strsplit(path2->path, ' ');
	while (p1[++i] && (j = -1))
	{
		t_p1 = ft_atoi(p1[i]);
		while (p2[++j])
		{
			if (t_p1 == ft_atoi(p2[j]))
				b += 1;
		}
	}
	ft_ppdel(&p1);
	ft_ppdel(&p2);
	if (b == 1)
		return (1);
	else
		return (0);
}

void			ft_path_to_stack(t_stack *stack, t_stack stk,
	t_uint j, t_path **set)
{
	int		n;
	t_uint	id;

	n = stack_size(stack);
	while (n)
	{
		id = (t_uint)stk.bot_node->id;
		if (ft_path_cmp(set[id], set[j], -1, -1) == NOT_PARALLEL && id != j)
			return ;
		stk.bot_node = stk.bot_node->top_elem;
		--n;
	}
	push(stack, j);
}

void			ft_path_to_data(t_data *input, t_path **set, t_uint set_size)
{
	t_stack			stack;
	register t_uint	i;
	register t_uint	j;
	char			**storage;
	t_uint			size;

	size = 0;
	i = -1;
	stack_init(&stack);
	storage = NULL;
	while (++i < set_size && (j = -1))
	{
		push(&stack, i);
		while (++j < set_size)
		{
			if (ft_path_cmp(set[i], set[j], -1, -1) && i != j)
				ft_path_to_stack(&stack, stack, j, set);
		}
		size += 1;
		storage = ft_temp_result(&stack, storage, size);
	}
	storage = ft_storage_clean_up(storage, &size);
	input->path = ft_illative_path(storage, input->leming_n, set, size);
	ft_ppdel(&storage);
}
