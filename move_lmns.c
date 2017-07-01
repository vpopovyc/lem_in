/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_lmns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 13:57:36 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/04/15 19:57:33 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_move_allong(t_data *input, t_root *root, t_uint i, t_uint *stor)
{
	if (i == SHORTEST_PATH && stor[i])
	{
		ft_push_all_leming_ahead(1, 1, ft_st(root->binds), root->binds);
		ft_push_leming(1, stor[i], root->binds, &input->last_node);
		stor[i] = 0;
	}
	else
	{
		ft_push_all_leming_ahead(i + 1, input->last_node[i + 1],
				ft_st(root->binds), root->binds);
		input->last_node[i + 1] += 1;
	}
}

void	ft_query_to_path(t_stack *stack, t_data *input, t_root *root)
{
	t_uint	stor[input->size];
	t_uint	i;

	ft_fill_stor(stack, stor, input->size);
	i = UINT_MAX;
	while (++i < input->size)
	{
		if (stor[i] > input->path[i]->lenght)
		{
			input->u_size += 1;
			ft_push_all_leming_ahead(i + 1, 1, ft_st(root->binds), root->binds);
			ft_push_leming(i + 1, stor[i], root->binds, &input->last_node);
			stor[i] = 0;
		}
		else
			ft_move_allong(input, root, i, stor);
	}
	ft_push_back_to_stack(stack, stor, input->size);
}

void	ft_last_node_mark(t_data *input)
{
	t_uint	i;

	i = UINT_MAX;
	input->last_node = (t_uint*)malloc(sizeof(t_uint) * (input->size + 1));
	input->last_node[input->size] = (t_uint)NULL;
	while (++i < input->size)
		input->last_node[i] = 0;
}

t_uint	ft_check_node(t_path **path, t_uint size,
	t_uint *last_node, t_uint u_size)
{
	t_uint			i;
	static t_uint	j;

	i = UINT_MAX;
	while (++i < size)
	{
		if (path[i]->lenght + 1 == last_node[i + 1])
			++j;
	}
	if (j == u_size || j == size)
		return (0);
	else
		return (1);
}

void	ft_move(t_data *input, t_root *root)
{
	t_stack		leming;

	ft_putstr("\033[0;92m");
	ft_psn(input->input, (t_uint)ft_strlen(input->input));
	write(1, "\n", 1);
	if (input->path[0]->lenght == 1)
		ft_push_all_once(root->binds, input->leming_n);
	else
	{
		stack_init(&leming);
		input->u_size = 1;
		ft_fill_stack(&leming, input->leming_n);
		ft_last_node_mark(input);
		while (ft_check_node(input->path, input->size,
					input->last_node, input->u_size) || stack_size(&leming))
		{
			write(1, "\n", 1);
			ft_query_to_path(&leming, input, root);
		}
	}
}
