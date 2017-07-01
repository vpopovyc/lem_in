/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   root_path_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 18:56:20 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/04/15 20:08:14 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char		*ft_stack_to_str(t_stack stack)
{
	int		n;
	char	*sv;
	char	*t_sv;

	sv = ft_strnew(0);
	n = stack_size(&stack);
	while (--n)
	{
		stack.bot_node = stack.bot_node->top_elem;
		t_sv = ft_itoa(stack.bot_node->id);
		sv = ft_strnfjoin(sv, t_sv, ft_strlen(t_sv));
		if (n > 1)
			sv = ft_strnfjoin(sv, " ", 1);
		free(t_sv);
	}
	return (sv);
}

static t_path	*ft_new_path(t_stack stack)
{
	t_path	*new_path;

	new_path = (t_path*)malloc(sizeof(t_path));
	new_path->path = ft_stack_to_str(stack);
	new_path->lenght = stack_size(&stack) - START;
	return (new_path);
}

static t_path	**ft_repath_to_root(t_path **old_path_set, t_uint n_ofpaths)
{
	t_path			**new_path_set;
	register t_uint	i;

	i = UINT_MAX;
	new_path_set = (t_path**)malloc(sizeof(t_path*) * (n_ofpaths + 1));
	new_path_set[n_ofpaths] = NULL;
	while (++i != n_ofpaths && n_ofpaths > 1)
		new_path_set[i] = old_path_set[i];
	if (n_ofpaths > 1)
		free(old_path_set);
	return (new_path_set);
}

void			ft_path_to_root(t_root *root, t_stack stack)
{
	t_path		**new_path_set;

	root->n_ofpaths += 1;
	new_path_set = ft_repath_to_root(root->path_set, root->n_ofpaths);
	new_path_set[root->n_ofpaths - 1] = ft_new_path(stack);
	root->path_set = new_path_set;
}
