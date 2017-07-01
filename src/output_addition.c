/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_addition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 18:01:04 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/04/15 19:59:31 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_fill_stack(t_stack *stack, t_uint n)
{
	t_uint	i;

	i = 0;
	while (++i <= n)
		push(stack, i);
}

void	ft_fill_stor(t_stack *stack, t_uint *ar, t_uint size)
{
	t_uint	i;
	t_uint	n;

	i = UINT_MAX;
	while (++i < size)
		ar[i] = 0;
	n = stack_size(stack);
	if (n < size)
		size = n;
	i = UINT_MAX;
	while (++i < size)
	{
		ar[i] = top(*stack);
		pop(stack);
	}
}

t_room	*ft_find_room(t_uint path_id, t_uint path_node, t_room **set)
{
	t_uint	i;

	i = UINT_MAX;
	while (set[++i])
	{
		if (set[i]->path_id == path_id)
			if (set[i]->path_node == path_node)
				return (set[i]);
	}
	return ((t_room*)NULL);
}

t_room	*ft_st(t_room **set)
{
	t_uint	i;

	i = UINT_MAX;
	while (set[++i])
	{
		if (set[i]->flag == START_ROOM)
			return (set[i]);
	}
	return ((t_room*)NULL);
}

void	ft_push_back_to_stack(t_stack *stack, t_uint *ar, t_uint size)
{
	t_uint i;

	i = UINT_MAX;
	while (++i != size)
	{
		if (ar[i] != 0)
			push(stack, ar[i]);
	}
}
