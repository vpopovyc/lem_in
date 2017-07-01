/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:18:41 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/04/15 19:46:05 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_exit(char *sv)
{
	ft_putstr("\033[01;31m");
	ft_putendl(sv);
	ft_putstr("\x1b[0m");
	exit(-1);
}

static void		ft_tdata_init(t_data *new)
{
	new->input = ft_strnew(0);
}

int				main(void)
{
	t_acmx	mx;
	t_data	input;
	t_root	root;

	ft_tdata_init(&input);
	ft_get_input(&input, &mx, &root);
	ft_find_connection_component(mx.acmx, root.n_ofbinds);
	ft_path_traversal(&root, mx.acmx, root.n_ofbinds);
	ft_path_to_data(&input, root.path_set, root.n_ofpaths);
	input.size = ft_spot_rooms(input.path, root.binds);
	ft_move(&input, &root);
	return (0);
}
