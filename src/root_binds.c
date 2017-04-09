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

void    ft_validate_names_to_instructions(t_room **binds, int n)
{
    char    v_flag;

    v_flag = 0;
    while (--n >= 0)
    {
        if (((*(binds + n))->flag) == 0x1)
        {
            if ((v_flag ^ 0x2) & 0x1)
                ft_exit("Wrong general instuctions: duplicated");
            v_flag |= 0x1;
        }
        if (((*(binds + n))->flag) == 0x2)
        {
            if ((v_flag ^ 0x1) & 0x2)
                ft_exit("Wrong general instuctions: duplicated");
            v_flag |= 0x2;
        }
    }
    if (v_flag ^ 0x3)
        return (ft_exit("Missing general instruction"));
}

t_room	**ft_rebind_rooms(t_room **old_binds, uint n_ofbinds)
{
	t_room	**new_binds;
	int		i;
	
	i = -1;
	new_binds = (t_room**)malloc(sizeof(t_room*) * (n_ofbinds + 1));
	new_binds[n_ofbinds] = NULL;
	while (++i != n_ofbinds && n_ofbinds > 1)
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
    if ((*node)->flag == 0x1)
        root->start = (*node)->id;
    else if ((*node)->flag == 0x2)
        root->end = (*node)->id;
	root->binds = new_binds;
}
