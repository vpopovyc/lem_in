/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   root_binds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 17:05:52 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/03/26 17:05:53 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	**ft_rebind_rooms(t_room **old_binds, uint n_ofbinds)
{
	t_room	**new_binds;
	int		i;
	
	i = -1;
	n_ofbinds += 1;
	new_binds = (t_room**)malloc(sizeof(t_room*) * (n_ofbinds + 1));
	new_binds[n_ofbinds] = NULL;
	while (++i != n_ofbinds)
		new_binds[i] = old_binds[i];
	if (n_ofbinds > 1)
		free(old_binds);
	return (new_binds);
}

void	ft_bind_to_root(t_root *root, t_room **node)
{
	t_room **new_binds;
	
	root->n_ofbinds += 1;
	new_binds = ft_rebind_rooms(root->binds, root->n_ofbinds);
	new_binds[root->n_ofbinds - 1] = *node;
	root->binds = new_binds;
}
